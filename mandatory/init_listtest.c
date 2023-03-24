/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_listtest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:27:15 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/24 10:08:55 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	error_func(t_dlist **list)
{
	write(2, "Error\n", 6);
	if (list)
		free_list(list);
	exit(EXIT_FAILURE);
}

int	checking_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][0] == '-' || argv[i][0] == '+') && j == 0)
				j++;
			else if (ft_isdigit(argv[i][j]) != 1)
				error_func(NULL);
			else
				j++;
		}
		if (*argv[i] == '\0')
			error_func(NULL);
		i++;
	}
	return (0);
}

t_dlist	*first_list(char **argv, int argc)
{
	t_dlist			*lst;
	long int		number;
	int				i;

	i = 1;
	number = ft_atol(argv[1]);
	if (number > 2147483647 || number < -2147483648)
		error_func(NULL);
	lst = ft_createnode(number);
	i++;
	while (i < argc)
	{
		number = ft_atol(argv[i]);
		if (number > 2147483647 || number < -2147483648)
			error_func(&lst);
		lst->next = ft_createnode(number);
		lst->next->prev = lst;
		lst = lst->next;
		i++;
	}
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

int	checking_list(t_dlist *lst)
{
	t_dlist	*new;

	new = lst;
	while (lst)
	{
		new = lst->next;
		while (new)
		{
			if (new->data == lst->data)
				error_func(&lst);
			new = new->next;
		}
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	while (lst->prev)
		lst = lst->prev;
	return (0);
}

long int	ft_atol(const char *nptr)
{
	int			i;
	long int	number;
	int			signal;

	i = 0;
	signal = 1;
	number = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (is_signal(nptr[i]) == 1)
	{
		signal = return_s(nptr[i]) * signal;
		i++;
	}
	while (nptr[i] != '\0' && is_number(nptr[i]) == 1)
	{
		number = 10 * number + (nptr[i] - '0');
		i++;
	}
	return (number * signal);
}

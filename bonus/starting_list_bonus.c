/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_list_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:06:04 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/19 16:07:18 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap_bonus.h"

void	error_func_bonus(t_dlist **list, int a, char *argv[], int i)
{
	int	j;

	j = 0;
	while (argv[j])
		j++;
	write(2, "Error\n", 6);
	if (!ft_strncmp(argv[j - 1], "-details", 8) && i == 1)
		ft_printf("The argument: %s(%d) is not an int.\n", argv[a], a);
	else if (!ft_strncmp(argv[j - 1], "-details", 8) && i == 2)
		ft_printf("The argument: %s(%d) is larger than an int.\n", argv[a], a);
	else if (!ft_strncmp(argv[j - 1], "-details", 8) && i == 3)
		ft_printf("The argument: %s(%d) appears for a second time.\n", argv[a], a);
	else
		ft_printf("Run the checker with '-details' for specific errors.\n");
	if (list)
		free_list(list);
	exit(EXIT_FAILURE);
}

int	checking_digits_bonus(char **argv)
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
			if (argv[i][0] == '-' || argv[i][0] == '+')
				j++;
			else if (ft_isdigit(argv[i][j]) != 1)
				error_func_bonus(NULL, i, argv, 1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

t_dlist	*first_list_bonus(char **argv, int argc)
{
	t_dlist			*lst;
	long int		number;
	int				i;

	i = 1;
	number = ft_atol(argv[1]);
	if (number > 2147483647 || number < -2147483648)
		error_func_bonus(NULL, argc, argv, 2);
	lst = ft_createnode(number);
	i++;
	while (i < argc)
	{
		number = ft_atol(argv[i]);
		if (number > 2147483647 || number < -2147483648)
			error_func_bonus(&lst, i, argv, 2);
		lst->next = ft_createnode(number);
		lst->next->prev = lst;
		lst = lst->next;
		i++;
	}
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

int	checking_list_bonus(t_dlist *lst,  char *argv[])
{
	t_dlist	*new;
	int		i;

	new = lst;
	while (lst)
	{
		new = lst->next;
		i = 1;
		while (new)
		{
			i++;
			if (new->data == lst->data)
				error_func_bonus(&lst, i, argv, 3);
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

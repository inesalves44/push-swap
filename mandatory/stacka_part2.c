/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacka_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:27:15 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/02 23:50:43 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*stack_creation(char *args, t_dlist *head)
{
	t_dlist	*lst_temp;
	int		number;

	lst_temp = NULL;
	if (args[0] == '0' && ft_strlen(args) == 1)
		number = 0;
	else
	{
		number = ft_atoi(args);
		if (!number)
		{	
			ft_printf("Error\n");
			free_list(&head);
			exit (EXIT_FAILURE);
		}
	}
	lst_temp = ft_createnode(number);
	lst_temp->prev = head;
	head->next = lst_temp;
	return (lst_temp);
}

t_dlist	*first_list(char **argv, int argc)
{
	t_dlist	*lst;
	int		number;
	int		i;

	i = 1;
	if (argv[1][0] == '0' && ft_strlen(argv[1]) == 1)
		number = 0;
	else
	{
		number = ft_atoi(argv[1]);
		if (!number)
		{	
			ft_printf("Error\n");
			exit (EXIT_FAILURE);
		}
	}
	lst = ft_createnode(number);
	i++;
	while (i < argc)
	{
		lst->next = stack_creation(argv[i], lst);
		lst = lst->next;
		i++;
	}
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
				return (1);
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

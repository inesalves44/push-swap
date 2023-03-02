/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:58:30 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/02 22:07:52 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_dlist	*rotate(t_dlist *lst, int a)
{
	int		temp;

	lst = reorder_stacks(lst);
	temp = lst->data;
	while (lst)
	{
		if (lst->next)
			lst->data = lst->next->data;
		else
		{
			lst->data = temp;
			break ;
		}
		lst = lst->next;
	}
	if (a == 1)
		ft_printf("ra\n");
	else if (a == 2)
		ft_printf("rb\n");
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

t_dlist	*r_rotate(t_dlist *lst, int a)
{
	int		temp;

	lst = reorder_stacks(lst);
	while (lst->next)
		lst = lst->next;
	temp = lst->data;
	while (lst)
	{
		if (lst->prev)
			lst->data = lst->prev->data;
		else
		{
			lst->data = temp;
			break ;
		}
		lst = lst->prev;
	}
	if (a == 1)
		ft_printf("rra\n");
	else if (a == 2)
		ft_printf("rrb\n");
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

t_dlist	*swap(t_dlist *test, int a)
{
	int		temp;

	test = reorder_stacks(test);
	if (test)
	{
		temp = test->data;
		test->data = test->next->data;
		test->next->data = temp;
		if (a == 1)
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
	while (test->prev)
		test = test->prev;
	return (test);
}

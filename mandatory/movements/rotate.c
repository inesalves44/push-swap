/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:58:30 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/24 00:12:31 by idias-al         ###   ########.fr       */
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
			break;
		}
		lst = lst->next;
	}
	if (a == 1)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

void	rotate_total(t_dlist *stack_a, t_dlist *stack_b)
{
	rotate(stack_a, 1);
	rotate(stack_b, 0);
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
	else
		ft_printf("rrb\n");
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

void	r_rotate_total(t_dlist *stack_a, t_dlist *stack_b)
{
	r_rotate(stack_a, 1);
	r_rotate(stack_b, 0);
}
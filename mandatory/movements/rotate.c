/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:58:30 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/27 11:38:23 by idias-al         ###   ########.fr       */
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

void	rotate_total(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*lsta;
	t_dlist	*lstb;

	lsta = *stack_a;
	lstb = *stack_b;
	lsta = rotate(lsta, 0);
	lstb = rotate(lstb, 0);
	stack_a = &lsta;
	stack_b = &lstb;
	ft_printf("rr\n");
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

void	r_rotate_total(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*lsta;
	t_dlist	*lstb;

	lsta = *stack_a;
	lsta = *stack_b;
	lsta = r_rotate(lsta, 0);
	lsta = r_rotate(lstb, 0);
	stack_a = &lsta;
	stack_b = &lstb;
	ft_printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:58:30 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/22 16:02:41 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_dlist	*rotate(t_dlist *head, int a)
{
	t_dlist	*lst;
	int		temp;

	lst = head;
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
	while (lst->prev)
		lst = lst->prev;
	if (a == 1)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
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
	t_dlist	*stacka;

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
	stacka = lst;
	return (stacka);
}

void	r_rotate_total(t_dlist *stack_a, t_dlist *stack_b)
{
	r_rotate(stack_a, 1);
	r_rotate(stack_b, 0);
}
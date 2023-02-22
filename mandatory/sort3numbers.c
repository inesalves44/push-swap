/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:12:09 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/22 15:58:11 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*checking_lastcase(t_dlist *stacka, t_dlist **lstb, int aux)
{
	t_dlist	*node;
	t_dlist	*stackb;
	int		temp;

	if (aux == 1)
		stackb = *lstb;
	else
		stackb = NULL;
	temp = stacka->data;
	node = ft_createnode(temp);
	stackb = insert_node(*lstb, node);
	ft_printf("pb\n");
	stacka = delete_node(stacka);
	stacka = swap(stacka, 1);
	if (aux == 1)
	{
		*lstb = stackb;
		return (stacka);
	}
	else
	{
		temp = stackb->data;
		node = ft_createnode(temp);
		stacka = insert_node(stacka, node);
		stackb = delete_node(stackb);
		ft_printf("pa\n");
	}
	return(stacka);
}

t_dlist	*sort3numbers(t_dlist *stacka, t_dlist **stackb)
{
	t_dlist	*lst;
	int		aux;

	aux = 0;
	if (!stackb)
		stackb = NULL;
	else
		aux = 1;
	lst = stacka;
	if (lst->data < lst->next->data && lst->data > lst->next->next->data)
	{
		stacka = r_rotate(lst, 1);
		return (stacka);
	}
	else if (lst->data > lst->next->data)
	{
		if (lst->data > lst->next->next->data && lst->next->next)
			rotate(stacka, 1);
		lst = stacka;
		if (lst->data > lst->next->data)
			stacka = swap(lst, 1);
		return (stacka);
	}
	else if (lst->next->data > lst->next->next->data)
		stacka = checking_lastcase(stacka, stackb, aux);
	return (stacka);
}

void	checking_lastcase_rev(t_dlist *stacka, t_dlist *stackb)
{
	t_dlist	*lsta;
	t_dlist	*lstb;
	t_dlist	*node;
	int		temp;

	lsta = stacka;
	lstb = stackb;
	temp = lstb->data;
	node = ft_createnode(temp);
	stacka = insert_node(lsta, node);
	lsta = stacka;
	ft_printf("pa\n");
	stackb = delete_node(lstb);
	lstb = stackb;
	stackb = swap(lstb, 0);
}

t_dlist	*sort3numbers_rev(t_dlist *stackb, t_dlist *stacka)
{
	t_dlist	*lst;

	lst = stackb;
	if (lst->data > lst->next->data && lst->data < lst->next->next->data)
		stackb = r_rotate(lst, 0);
	else if (lst->data < lst->next->data)
	{
		if (lst->data < lst->next->next->data && lst->next->next)
			lst = rotate(stackb, 0);
		lst = stackb;
		if (lst->data < lst->next->data)
			stackb = swap(lst, 0);
	}
	else if (lst->next->data < lst->next->next->data)
		checking_lastcase_rev(stackb, stacka);
	reorder_stacks(&stacka, &stackb);
	return (stackb);
}

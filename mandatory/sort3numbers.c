/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:12:09 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/23 15:20:18 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*sort3numbers(t_dlist *stacka, t_dlist **stackb)
{
	if (!stackb)
		stackb = NULL;
	if (stacka->data == get_max(stacka))
		stacka = rotate(stacka, 1);
	else if (stacka->next->data == get_max(stacka))
		stacka = r_rotate(stacka, 1);
	if (stacka->data > stacka->next->data)
		stacka = swap(stacka, 1);
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
	(void)stacka;
	if (stackb->data == get_min(stackb))
		stackb = rotate(stackb, 1);
	else if (stackb->next->data == get_min(stackb))
		stackb = r_rotate(stackb, 1);
	if (stackb->data > stackb->next->data)
		stackb = swap(stackb, 1);
	return (stackb);
}

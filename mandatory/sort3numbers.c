/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:12:09 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/02 01:09:27 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*sort3numbers(t_dlist *stacka)
{
	if (stacka->data == get_max(stacka))
		stacka = rotate(stacka, 1);
	else if (stacka->next->data == get_max(stacka))
		stacka = r_rotate(stacka, 1);
	if (stacka->data > stacka->next->data)
		stacka = swap(stacka, 1);
	return (stacka);
}

t_dlist	*sort3numbers_rev(t_dlist *stackb)
{
	if (stackb->data == get_min(stackb))
		stackb = rotate(stackb, 2);
	else if (stackb->next->data == get_min(stackb))
		stackb = r_rotate(stackb, 2);
	if (stackb->data < stackb->next->data)
		stackb = swap(stackb, 2);
	return (stackb);
}

t_dlist	*check_top_rev(t_dlist *lstb, t_dlist **stacka, int max, int max2)
{
	if (lstb->data == max || lstb->data == max2)
	{
		*stacka = pushing_to_stack(lstb, *stacka, 2);
		lstb = deletefromstack(lstb, 2, 1);
		lstb = check_top_rev(lstb, stacka, max, max2);
	}
	else if (ft_tdsize(lstb) >= 4)
	{
		while (lstb->prev)
			lstb = lstb->prev;
		lstb = rotate(lstb, 2);
		lstb = check_top_rev(lstb, stacka, max, max2);
	}
	return (lstb);
}

t_dlist	*sort5numbers_rev(t_dlist *stackb, t_dlist **stacka)
{
	int		max;
	t_dlist	*lsta;

	lsta = *stacka;
	max = get_max(stackb);
	stackb = check_top_rev(stackb, &lsta, max, max - 1);
	stackb = reorder_stacks(stackb);
	if (checking_ifordered(stackb, 2) == 0)
		stackb = sort3numbers_rev(stackb);
	if (lsta->data > lsta->next->data)
		lsta = swap(lsta, 1);
	stacka = &lsta;
	return (stackb);
}

t_dlist	*check_top(t_dlist *lsta, t_dlist **stackb, int min, int min2)
{
	if (lsta->data == min || lsta->data == min2)
	{
		*stackb = pushing_to_stack(lsta, *stackb, 2);
		lsta = deletefromstack(lsta, 2, 0);
		lsta = check_top(lsta, stackb, min, min2);
	}
	else if (ft_tdsize(lsta) >= 4)
	{
		while (lsta->prev)
			lsta = lsta->prev;
		lsta = rotate(lsta, 1);
		lsta = check_top(lsta, stackb, min, min2);
	}
	return (lsta);
}

t_dlist	*sort5numbers(t_dlist *stacka, t_dlist **lstb)
{
	int min;
	t_dlist	*stackb;

	stackb = *lstb;
	if (!stackb)
		stackb = NULL;
	min = get_min(stacka);
	stacka = check_top(stacka, &stackb, min, min + 1);
	stacka = reorder_stacks(stacka);
	if (checking_ifordered(stacka, 1) == 0 && ft_tdsize(stacka) > 2)
		stacka = sort3numbers(stacka);
	else if (checking_ifordered(stacka, 1) == 0 && ft_tdsize(stacka) <= 2)
		stacka = swap(stacka, 1);
	if (stackb->data < stackb->next->data)
		stackb = swap(stackb, 2);
	stacka = pushing_to_stack(stackb, stacka, 4);
	stackb = deletefromb(stackb);
	*lstb = stackb;
	return (stacka);
}

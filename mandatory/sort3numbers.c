/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:12:09 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/24 13:22:42 by idias-al         ###   ########.fr       */
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

t_dlist	*check_top(t_dlist *lsta, t_dlist **stackb)
{
	if (lsta->data == 1 || lsta->data == 2)
	{
		*stackb = pushing_tob(lsta, *stackb, 2);
		lsta = deletefroma(lsta, 2);
		lsta = check_top(lsta, stackb);
	}
	else if (ft_tdsize(*stackb) < 2)
	{
		lsta = rotate(lsta, 1);
		lsta = check_top(lsta, stackb);
	}
	return (lsta);
}

void	sort5numbers(t_dlist *stacka, t_dlist *stackb)
{
	stackb = NULL;
	stacka = check_top(stacka, &stackb);
	stacka = reorder_stacks(stacka);
	if (checking_ifordered(stacka) != 0 && ft_tdsize(stacka) >= 3)
		stacka = sort3numbers(stacka, &stackb);
	else if (checking_ifordered(stacka) != 0 && ft_tdsize(stacka) < 3)
		stacka = swap(stacka, 1);
	if (checking_ifordered_b(stackb) != 0)
		stackb = swap(stackb, 2);
	stacka = pushing_toa(stacka, stackb);
	deletefromb(stackb);
	free_list(&stacka);
}

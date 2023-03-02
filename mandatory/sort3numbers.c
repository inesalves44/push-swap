/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:12:09 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/02 23:04:38 by idias-al         ###   ########.fr       */
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

t_dlist	*check_top(t_dlist *lsta, t_dlist **stackb, int min, int min2)
{
	if (lsta->data == min || lsta->data == min2)
	{
		*stackb = push(*stackb, &lsta, 'b', 'n');
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
	stacka = push(stacka, &stackb, 'a', 'f');
	*lstb = stackb;
	return (stacka);
}

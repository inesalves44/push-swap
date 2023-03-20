/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:12:09 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/20 16:44:05 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*sort3numbers(t_dlist *stacka, t_utils *utils)
{
	if (stacka->data == get_max(stacka))
		stacka = rotate(stacka, utils);
	else if (stacka->next->data == get_max(stacka))
		stacka = r_rotate(stacka, utils);
	if (stacka->data > stacka->next->data)
		stacka = swap(stacka, utils);
	return (stacka);
}

t_dlist	*sort3numbers_rev(t_dlist *stacka, t_utils *utils)
{
	utils->rotate_total = 'b';
	if (stacka->data == get_min(stacka))
		stacka = rotate(stacka, utils);
	else if (stacka->next->data == get_min(stacka))
		stacka = r_rotate(stacka, utils);
	if (stacka->data < stacka->next->data)
		stacka = swap(stacka, utils);
	return (stacka);
}

t_dlist	*check_top(t_dlist *lsta, t_dlist **stackb, t_utils *utils)
{
	if (lsta->data == utils->min || lsta->data == utils->min + 1)
	{
		*stackb = push(*stackb, &lsta, utils);
		lsta = check_top(lsta, stackb, utils);
	}
	else if ((utils->size == 5 && ft_tdsize(lsta) >= 4) \
			|| (utils->size == 4 && ft_tdsize(lsta) >= 3))
	{
		while (lsta->prev)
			lsta = lsta->prev;
		lsta = rotate(lsta, utils);
		lsta = check_top(lsta, stackb, utils);
	}
	while (lsta->prev)
		lsta = lsta->prev;
	return (lsta);
}

t_dlist	*sort5numbers(t_dlist *stacka, t_dlist **lstb, t_utils *utils)
{
	t_dlist	*stackb;

	stackb = *lstb;
	if (!stackb)
		stackb = NULL;
	stacka = check_top(stacka, &stackb, utils);
	if (checking_ifordered(stacka, 1) == 0 && ft_tdsize(stacka) > 2)
		stacka = sort3numbers(stacka, utils);
	else if (checking_ifordered(stacka, 1) == 0 && ft_tdsize(stacka) <= 2)
		stacka = swap(stacka, utils);
	if (stackb->data < stackb->next->data)
		stackb = swap_b(stackb, utils);
	stacka = push_final(stacka, &stackb, utils);
	*lstb = stackb;
	return (stacka);
}

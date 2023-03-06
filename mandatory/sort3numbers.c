/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:12:09 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/06 16:26:19 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*sort3numbers(t_dlist *stacka, char **str)
{
	if (stacka->data == get_max(stacka))
		stacka = rotate(stacka, 1, str);
	else if (stacka->next->data == get_max(stacka))
		stacka = r_rotate(stacka, 1, str);
	if (stacka->data > stacka->next->data)
		stacka = swap(stacka, 1, str);
	return (stacka);
}

t_dlist	*check_top(t_dlist *lsta, t_dlist **stackb, int min, int min2, char **str)
{
	if (lsta->data == min || lsta->data == min2)
	{
		*stackb = push(*stackb, &lsta, 'b', 'n', str);
		lsta = check_top(lsta, stackb, min, min2, str);
	}
	else if (ft_tdsize(lsta) >= 4)
	{
		while (lsta->prev)
			lsta = lsta->prev;
		lsta = rotate(lsta, 1, str);
		lsta = check_top(lsta, stackb, min, min2, str);
	}
	return (lsta);
}

t_dlist	*sort5numbers(t_dlist *stacka, t_dlist **lstb, char **str)
{
	int min;
	t_dlist	*stackb;

	stackb = *lstb;
	if (!stackb)
		stackb = NULL;
	min = get_min(stacka);
	stacka = check_top(stacka, &stackb, min, min + 1, str);
	stacka = reorder_stacks(stacka);
	if (checking_ifordered(stacka, 1) == 0 && ft_tdsize(stacka) > 2)
		stacka = sort3numbers(stacka, str);
	else if (checking_ifordered(stacka, 1) == 0 && ft_tdsize(stacka) <= 2)
		stacka = swap(stacka, 1, str);
	if (stackb->data < stackb->next->data)
		stackb = swap(stackb, 2, str);
	stacka = push(stacka, &stackb, 'a', 'f', str);
	*lstb = stackb;
	return (stacka);
}

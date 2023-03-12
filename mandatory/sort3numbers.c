/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:12:09 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/11 20:05:01 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*sort3numbers(t_dlist *stacka, t_utils *utils, char **str)
{
	(void)utils;
	if (stacka->data == get_max(stacka))
		stacka = rotate(stacka, str);
	else if (stacka->next->data == get_max(stacka))
		stacka = r_rotate(stacka, str);
	if (stacka->data > stacka->next->data)
		stacka = swap(stacka, str);
	return (stacka);
}

t_dlist	*check_top(t_dlist *lsta, t_dlist **stackb, t_utils *utils, char **str)
{
	if (lsta->data == utils->min || lsta->data == utils->min + 1)
	{
		*stackb = push_b(*stackb, &lsta, str);
		lsta = check_top(lsta, stackb, utils, str);
	}
	else if ((utils->size == 5 && ft_tdsize(lsta) >= 4) || (utils->size == 4 && ft_tdsize(lsta) >= 3))
	{
		while (lsta->prev)
			lsta = lsta->prev;
		lsta = rotate(lsta, str);
		lsta = check_top(lsta, stackb, utils, str);
	}
	while (lsta->prev)
		lsta = lsta->prev;
	return (lsta);
}

t_dlist	*sort5numbers(t_dlist *stacka, t_dlist **lstb, t_utils *utils, char **str)
{
	t_dlist	*stackb;

	stackb = *lstb;
	if (!stackb)
		stackb = NULL;
	stacka = check_top(stacka, &stackb, utils, str);
	if (checking_ifordered(stacka, 1) == 0 && ft_tdsize(stacka) > 2)
		stacka = sort3numbers(stacka, utils, str);
	else if (checking_ifordered(stacka, 1) == 0 && ft_tdsize(stacka) <= 2)
		stacka = swap(stacka, str);
	if (stackb->data < stackb->next->data)
		stackb = swap_b(stackb, str);
	stacka = push_final(stacka, &stackb, str);
	*lstb = stackb;
	return (stacka);
}

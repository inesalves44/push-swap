/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:29:48 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/13 12:05:57 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*separate_stacka_a(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	if (((stacka->data >> utils->sig) & 1) == 0)
		*stackb = push_b(*stackb, &stacka, str);
	else
		stacka = rotate(stacka, str);
	while (stacka)
	{
		if (((stacka->data >> utils->sig) & 1) == 0)
			break ;
		else if (!stacka->next)
		{
			while (stacka->prev)
				stacka = stacka->prev;
			return(stacka);
		}
		stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	stacka = separate_stacka_a(stacka, stackb, utils, str);
	return (stacka);
}

t_dlist	*sort500numbers(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	utils->sig = 0;
	while (stacka->next)
		stacka = stacka->next;
	while (((stacka->data >> utils->sig) & 1) == 0)
	{
		while (stacka->prev)
			stacka = stacka->prev;
		stacka = r_rotate(stacka, str);
		*stackb = push_b(*stackb, &stacka, str);
		while (stacka->next)
			stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	while (utils->sig < 9)
	{
		stacka = separate_stacka_a(stacka, stackb, utils, str);
		stacka = push_final(stacka, stackb, str);
		utils->sig++;
	}
	while (stacka->data != 255)
		*stackb = push_b(*stackb, &stacka, str);
	stacka = rotate(stacka, str);
	while (stacka->data != 256)
		*stackb = push_b(*stackb, &stacka, str);
	stacka = r_rotate(stacka, str);
	stacka = push_final(stacka, stackb, str);
	return (stacka);
}
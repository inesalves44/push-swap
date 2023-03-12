/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:29:48 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/12 15:08:20 by idias-al         ###   ########.fr       */
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

t_dlist	*separate_stacka_b(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	if ((((*stackb)->data >> utils->sig) & 1) == 1)
		stacka = push_b(stacka, stackb, str);
	else
		*stackb = rotate(*stackb, str);
	while (*stackb)
	{
		if ((((*stackb)->data >> utils->sig) & 1) == 1)
			break ;
		else if (!(*stackb)->next)
		{
			while ((*stackb)->prev)
				*stackb = (*stackb)->prev;
			return(stacka);
		}
		*stackb = (*stackb)->next;
	}
	while ((*stackb)->prev)
		(*stackb) = (*stackb)->prev;
	stacka = separate_stacka_b(stacka, stackb, utils, str);
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
		utils->sig++;
		stacka = separate_stacka_b(stacka, stackb, utils, str);
	}
	while (stacka->data != 256)
	{
		if ((*stackb)->data != 255)
			*stackb = rotate_b(*stackb, str);
		stacka = rotate(stacka, str);
	}
	*stackb = push_b(*stackb, &stacka, str);
	while (stacka->data != get_min(stacka))
		stacka = r_rotate(stacka, str);
	stacka = push(stacka, stackb,str);
	stacka = push(stacka, stackb,str);
	while ((*stackb)->data != get_max(*stackb))
		*stackb = r_rotate_b(*stackb, str);
	stacka = push_final(stacka, stackb, str);
	while (stacka->data != 128)
		*stackb = push_b(*stackb, &stacka, str);
	*stackb = push_b(*stackb, &stacka, str);
	while (stacka->data != 160)
		*stackb = push_b(*stackb, &stacka, str);
	*stackb = push_b(*stackb, &stacka, str);
	while (stacka->data != 224)
		*stackb = push_b(*stackb, &stacka, str);
	*stackb = push_b(*stackb, &stacka, str);
	while (stacka->data != 240)
		*stackb = push_b(*stackb, &stacka, str);
	*stackb = push_b(*stackb, &stacka, str);
	while (stacka->data != 320)
		*stackb = push_b(*stackb, &stacka, str);
	*stackb = push_b(*stackb, &stacka, str);
	while (stacka->data != 416)
		*stackb = push_b(*stackb, &stacka, str);
	*stackb = push_b(*stackb, &stacka, str);
	checking_ifordered(stacka, 1);
	print_dblist2(stacka, *stackb);
	return (stacka);
}
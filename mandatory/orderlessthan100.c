/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderlessthan100.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:05:00 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/14 11:42:57 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist *separte_stacks(t_dlist *stacka, t_dlist **stackb, char **str, t_utils *utils)
{
	int		aux2;

	aux2 = 0;
	if (stacka->data <= utils->half && utils->high == 0)
	{
		*stackb = push_b(*stackb, &stacka, str);
		if ((*stackb)->next)
		{
			if ((*stackb)->data <= utils->half / 4 && (*stackb)->next->data > utils->half / 4)
				*stackb = rotate_b(*stackb, str);
			else if ((*stackb)->data <= (utils->half / 4 * 3) && (*stackb)->next->data > (utils->half / 4 * 3))
				*stackb = swap_b(*stackb, str);
		}
		aux2 = 1;
	}
	else if (stacka->data > utils->half && utils->high == 1)
	{
		*stackb = push_b(*stackb, &stacka, str);
		if ((*stackb)->next)
		{
			if ((*stackb)->data < (utils->half + utils->half / 4) && (*stackb)->next->data > (utils->half + utils->half / 4))
				*stackb = rotate_b(*stackb, str);
			else if ((*stackb)->data <= (utils->half + utils->half / 4 * 3) && (*stackb)->next->data > (utils->half + utils->half / 4 * 3))
				*stackb = swap_b(*stackb, str);
		}
		aux2 = 1;
	}
	if (aux2 == 0)
		stacka = rotate(stacka, str);
	while (stacka)
	{
		if (stacka->data <= utils->half && utils->high == 0)
			break ;
		else if (stacka->data > utils->half && utils->high == 1)
			break ;
		else if (!stacka->next)
			return (stacka);
		stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	stacka = separte_stacks(stacka, stackb, str, utils);
	return(stacka);
}

int	get_pos(char *s, t_dlist *stackb)
{
	int		pos;
	
	if (find_number(stackb, get_min(stackb)) > ft_tdsize(stackb) / 2)
	{
		pos = ft_tdsize(stackb) - find_number(stackb, get_min(stackb)) + 1;
		*s = 's';
	}
	else
	{
		pos = find_number(stackb, get_min(stackb)) - 1;
		*s = 'f';
	}
	if (pos > ft_tdsize(stackb) - find_number(stackb, get_max(stackb)))
	{
		pos = ft_tdsize(stackb) - find_number(stackb, get_max(stackb)) + 1;
		*s = 's';
	}
	else if (pos >= find_number(stackb, get_max(stackb)))
	{
		pos = find_number(stackb, get_max(stackb)) - 1;
		*s = 'f';
	}
	return (pos);
}

t_dlist	*do_stackb(t_dlist *stackb, t_dlist **stacka, char **str, t_utils *utils)
{
	int		i;
	char	s;

	if (ft_tdsize(stackb) == 1)
	{
		*stacka = push_final(*stacka, &stackb, str);
		return (stackb);
	}
	utils->min_b = get_min(stackb);
	utils->pos = get_pos(&s, stackb);
	i = 0;
	while (i < utils->pos)
	{
		if (s == 'f')
			stackb = rotate_b(stackb, str);
		else
			stackb = r_rotate_b(stackb, str);
		i++;
	}
	*stacka = push(*stacka, &stackb, str);
	if (utils->min_b == (*stacka)->data)
		*stacka = rotate(*stacka, str);
	stackb = do_stackb(stackb, stacka, str, utils);
	return (stackb);
}

t_dlist	*sort100numbers(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	while (stacka->next)
		stacka = stacka->next;
	while (stacka->data <= utils->half)
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
	stacka = separte_stacks(stacka, stackb,str, utils);
	while (stacka->prev)
		stacka = stacka->prev;
	*stackb = do_stackb(*stackb, &stacka, str, utils);
	utils->high = 1;
	stacka = separte_stacks(stacka, stackb, str, utils);
	while (stacka->prev)
		stacka = stacka->prev;
	*stackb = do_stackb(*stackb, &stacka, str, utils);
	while (checking_ifordered(stacka, 1) != 1)
		stacka = rotate(stacka, str);
	return (stacka);
}
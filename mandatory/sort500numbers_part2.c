/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500numbers_part2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:04:13 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/15 11:43:32 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*separte_500a(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	if (ft_tdsize(*stackb) >= 2)
		return (stacka);
	if (stacka->data >= utils->half)
	{
		*stackb = push_b(*stackb, &stacka, str);
		if ((*stackb)->next)
			if ((*stackb)->data > (utils->half + utils->quarter))
				(*stackb) = rotate_b(*stackb, str);
	}
	else
		stacka = rotate(stacka, str);
	while (stacka)
	{
		if (stacka->data > utils->half)
			break ;
		else if (!stacka->next)
		{
			while (stacka->prev)
				stacka = stacka->prev;
			return (stacka); 
		}
		stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	stacka = separte_500a(stacka, stackb, utils, str);
	return (stacka);
}

t_dlist	*separate500quarter(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	if (stacka->data <= utils->quarter && stacka->data > utils->quarter_first)
	{
		*stackb = push_b(*stackb, &stacka, str);
		if ((*stackb)->next)
			if ((*stackb)->data < (utils->quarter - (utils->quarter - utils->quarter_first) / 2))
				*stackb = rotate_b(*stackb, str);
	}
	else
		stacka = rotate(stacka, str);
	while (stacka)
	{
		if (stacka->data <= utils->quarter && stacka->data > utils->quarter_first)
			break ;
		else if (!stacka->next)
		{
			while (stacka->prev)
				stacka = stacka->prev;
			return (stacka);
		}
		stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	stacka = separate500quarter(stacka, stackb, utils, str);
	return (stacka);
}

int	get_pos_2(char *s, t_dlist *stackb, int quarter)
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
	if (pos > ft_tdsize(stackb) - find_number(stackb, quarter))
	{
		pos = ft_tdsize(stackb) - find_number(stackb, quarter) + 1;
		*s = 's';
	}
	else if (pos >= find_number(stackb, quarter))
	{
		pos = find_number(stackb, quarter) - 1;
		*s = 'f';
	}
	return (pos);
}

t_dlist	*do_stackb_2(t_dlist *stackb, t_dlist **stacka, t_utils *utils, char **str)
{
	int		i;
	char	s;

	utils->min_b = get_min(stackb);
	utils->pos = get_pos_2(&s, stackb, utils->quarter);
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
	if (utils->quarter == (*stacka)->data)
		utils->quarter = utils->quarter - 1;
	while (stackb)
	{
		if (stackb->data <= utils->quarter)
			break ;
		else if (!stackb->next)
		{
			while (stackb->prev)
				stackb = stackb->prev;
			return (stackb);
		}
		stackb = stackb->next;
	}
	while (stackb->prev)
		stackb = stackb->prev;
	stackb = do_stackb_2(stackb, stacka, utils, str);
	return (stackb);
}
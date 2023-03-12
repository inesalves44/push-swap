/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:20:05 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/10 20:39:45 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*separte_500a(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	int	aux;

	aux = 0;
	if (stacka->data > utils->half)
	{
		*stackb = push_b(*stackb, &stacka, str);
		if ((*stackb)->next)
		{
			if ((*stackb)->data < (utils->half + utils->quarter))
				*stackb = rotate_b(*stackb, str);
			else if ((*stackb)->data < (utils->half) && (*stackb)->next->data > (utils->half + utils->quarter))
				*stackb = swap_b(*stackb, str);
		}
		aux = 1;
	}
	if (aux == 0)
		stacka = rotate(stacka, str);
	while (stacka)
	{
		if (stacka->data > utils->half)
			break ;
		else if (!stacka->next)
			return (stacka);
		stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	stacka = separte_500a(stacka, stackb, utils, str);
	return (stacka);
}

t_dlist	*separate500quarter(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	int	aux;

	aux = 0;
	if (stacka->data <= utils->quarter && stacka->data > utils->quarter_first)
	{
		*stackb = push_b(*stackb, &stacka, str);
		if ((*stackb)->next)
		{
			if ((*stackb)->data < (utils->quarter / 2 ))
				*stackb = rotate_b(*stackb, str);
		}
		aux = 1;
	}
	if (aux == 0)
		stacka = rotate(stacka, str);
	while (stacka)
	{
		if (stacka->data <= utils->quarter && stacka->data > utils->quarter_first)
			break ;
		else if (!stacka->next)
			return (stacka);
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
	utils->test = s;
	i = 0;
	while (i < utils->pos)
	{
		if (utils->test == 'f')
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
			return (stackb);
		stackb = stackb->next;
	}
	while (stackb->prev)
		stackb = stackb->prev;
	stackb = do_stackb_2(stackb, stacka, utils, str);
	return (stackb);
}


t_dlist	*sort500numbers(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	while (stacka->prev)
		stacka = stacka->prev;
	stacka = separte_500a(stacka, stackb, utils, str);
	while (stacka->prev)
		stacka = stacka->prev;
	stacka = separate500quarter(stacka, stackb, utils, str);
	while (stacka->prev)
		stacka = stacka->prev;
	*stackb = do_stackb_2(*stackb, &stacka, utils, str);
	while ((*stackb)->prev)
		(*stackb) = (*stackb)->prev;
	utils->quarter = utils->half;
	utils->quarter_first = utils->half - utils->half / 2;
	stacka = separate500quarter(stacka, stackb, utils, str);
	while (stacka->prev)
		stacka = stacka->prev;
	*stackb = do_stackb_2(*stackb, &stacka, utils, str);
	while ((*stackb)->prev)
		(*stackb) = (*stackb)->prev;
	while (stacka->data != get_min(stacka))
		stacka = rotate(stacka, str);
	utils->quarter = utils->half + utils->half / 2;
	utils->quarter_first = utils->half;
	while ((*stackb))
	{
		if ((*stackb)->data > utils->quarter)
			stacka = push(stacka, stackb, str);
		else if (ft_tdsize(*stackb) > (utils->half / 2))
			*stackb = rotate_b(*stackb, str);
		else
			break ;
	}
	*stackb = do_stackb(*stackb, &stacka, str, utils);
	utils->quarter = ft_tdsize(stacka);
	utils->quarter_first = utils->half + utils->half / 2;
	stacka = separate500quarter(stacka, stackb, utils, str);
	while (stacka->prev)
		stacka = stacka->prev;
	*stackb = do_stackb(*stackb, &stacka, str, utils);
	while (checking_ifordered(stacka, 1) != 1)
		stacka = rotate(stacka, str);
	return(stacka);
}
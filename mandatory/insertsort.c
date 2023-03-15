/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:19:45 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/13 16:31:23 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	get_pos_2(char *s, t_dlist *stacka, t_utils *utils)
{
	int		pos;
	
	if (find_number(stacka, utils->first) > ft_tdsize(stacka) / 2)
	{
		pos = ft_tdsize(stacka) - find_number(stacka,utils->first) + 1;
		*s = 's';
	}
	else
	{
		pos = find_number(stacka, utils->first) - 1;
		*s = 'f';
	}
	if (pos > ft_tdsize(stacka) - find_number(stacka, utils->second))
	{
		pos = ft_tdsize(stacka) - find_number(stacka, utils->second) + 1;
		*s = 's';
	}
	else if (pos >= find_number(stacka, utils->second))
	{
		pos = find_number(stacka, utils->second) - 1;
		*s = 'f';
	}
	return (pos);
}

int	get_pos_3(char *s, t_dlist **stackb, t_utils *utils)
{
	int		pos;
	
	if (find_number(*stackb, get_max(*stackb)) > ft_tdsize(*stackb) / 2)
	{
		pos = ft_tdsize(*stackb) - find_number(*stackb, get_max(*stackb)) + 1;
		*s = 's';
	}
	else
	{
		pos = find_number(*stackb, get_max(*stackb)) - 1;
		*s = 'f';
	}
	if (pos > ft_tdsize(*stackb) - find_number(*stackb, utils->insert))
	{
		pos = ft_tdsize(*stackb) - find_number(*stackb, utils->insert) + 1;
		*s = 's';
	}
	else if (pos >= find_number(*stackb, utils->insert))
	{
		pos = find_number(*stackb, utils->insert) - 1;
		*s = 'f';
	}
	return (pos);
}

t_dlist	*separate_a(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	int		i;
	char	s;

	if (ft_tdsize(stacka) == 1)
		return (stacka);
	while (stacka->data > utils->insert)
		stacka = stacka->next;
	utils->first = stacka->data;
	while (stacka->next)
		stacka = stacka->next;
	while (stacka->data > utils->insert)
		stacka = stacka->prev;
	utils->second = stacka->data;
	while (stacka->prev)
		stacka = stacka->prev;
	s = 'a';
	utils->pos = get_pos_2(&s, stacka, utils);
	i = 0;
	while (i < utils->pos)
	{
		if (s == 's')
			stacka = r_rotate(stacka, str);
		else
			stacka = rotate(stacka, str);
		i++;
	}
	*stackb = push_b(*stackb, &stacka, str);
	if ((*stackb)->next)
	{
		if ((*stackb)->data == get_min(*stackb))
			*stackb = rotate_b(*stackb, str);
		else if ((*stackb)->next->data > (*stackb)->data)
			*stackb = swap_b(*stackb, str);
	}
	while (stacka)
	{
		if (stacka->data < utils->insert)
		{
			while (stacka->prev)
				stacka = stacka->prev;
			stacka = separate_a(stacka, stackb, utils, str);
		}
		if (!stacka->next)
			break ;
		stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	return (stacka);
}

t_dlist	*separate_b(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	int		i;
	char	s;

	s = 'a';
	utils->pos = get_pos_3(&s, stackb, utils);
	i = 0;
	while (i < utils->pos)
	{
		if (s == 's')
			*stackb = r_rotate(*stackb, str);
		else
			*stackb = rotate(*stackb, str);
		i++;
	}
	stacka = push(stacka, stackb, str);
	if (stacka->data == utils->insert)
	{
		stacka = rotate(stacka, str);
		utils->insert++;
	}
	if (utils->min_prev != get_max(*stackb))
		stacka = separate_b(stacka, stackb, utils, str);
	return (stacka);
}

t_dlist	*separate_c(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	int		i;
	char	s;

	if (ft_tdsize(*stackb) == 1)
	{
		stacka = push_final(stacka, stackb, str);
		return (stacka);
	}
	s = 'a';
	utils->insert = get_min(*stackb);
	utils->pos = get_pos_3(&s, stackb, utils);
	i = 0;
	while (i < utils->pos)
	{
		if (s == 's')
			*stackb = r_rotate(*stackb, str);
		else
			*stackb = rotate(*stackb, str);
		i++;
	}
	stacka = push(stacka, stackb, str);
	if (stacka->data == utils->insert)
		stacka = rotate(stacka, str);
	stacka = separate_c(stacka, stackb, utils, str);
	return (stacka);
}

t_dlist	*sort500numbers(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	while (ft_tdsize(stacka) > 10)
	{
		stacka = separate_a(stacka, stackb, utils, str);
		utils->insert += (utils->size / 11);	
	}
	utils->insert -= (utils->size / 11);
	while (ft_tdsize(stacka) > 1)
	{
		if (stacka->data < utils->size)
			*stackb = push_b(*stackb, &stacka, str);
		else if (stacka->data == utils->size)
			stacka = rotate(stacka, str);
	}
	while (ft_tdsize(*stackb) > 10)
	{
		utils->min_prev = utils->insert - 1;
		stacka = separate_b(stacka, stackb, utils, str);
		while (checking_ifordered(stacka, 1) != 1)
			stacka = rotate(stacka, str);
		utils->insert -= (utils->size / 11);	
	}
	stacka = separate_c(stacka, stackb, utils, str);
	while (checking_ifordered(stacka, 1) != 1)
		stacka = rotate(stacka, str);
	return (stacka);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testquicksort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 23:19:38 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/11 20:27:59 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*check_last(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
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
	return (stacka);
}

t_dlist	*separate_stacka(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	if (stacka->data <= utils->half)
		*stackb = push_b(*stackb, &stacka, str);
	else
		stacka = rotate(stacka, str);
	while (stacka)
	{
		if (stacka->data <= utils->half)
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
	stacka = separate_stacka(stacka, stackb, utils, str);
	return (stacka);
}

int	get_pos_2(char *s, t_dlist *stackb, int min_group)
{
	int		pos;
	
	if (find_number(stackb, get_max(stackb)) > ft_tdsize(stackb) / 2)
	{
		pos = ft_tdsize(stackb) - find_number(stackb, get_max(stackb)) + 1;
		*s = 's';
	}
	else
	{
		pos = find_number(stackb, get_max(stackb)) - 1;
		*s = 'f';
	}
	if (pos > ft_tdsize(stackb) - find_number(stackb, min_group))
	{
		pos = ft_tdsize(stackb) - find_number(stackb, min_group) + 1;
		*s = 's';
	}
	else if (pos >= find_number(stackb, min_group))
	{
		pos = find_number(stackb, min_group) - 1;
		*s = 'f';
	}
	return (pos);
}

t_dlist	*add_values_a(t_dlist **stacka, t_dlist *stackb, t_utils *utils, char **str)
{
	char	s;
	int		i;

	s = 'a';
	i = 0;
	utils->pos = get_pos_2(&s, stackb, utils->med_b);
	while (i < utils->pos)
	{
		if (s == 'f')
			stackb = rotate_b(stackb, str);
		else
			stackb = r_rotate_b(stackb, str);
		i++;
	}
	*stacka = push(*stacka, &stackb, str);
	if ((*stacka)->data == utils->med_b && get_max(stackb) > utils->med_b)
	{
		*stacka = rotate(*stacka, str);
		utils->med_b++;
	}
	if (get_max(stackb) >= utils->med_b)
		stackb = add_values_a(stacka, stackb, utils, str);
	while (checking_ifordered(*stacka, 1) != 1)
		*stacka = rotate(*stacka, str);
	return (stackb);
}

t_dlist	*add_values_b(t_dlist **stacka, t_dlist *stackb, t_utils *utils, char **str)
{
	char	s;
	int		i;

	s = 'a';
	i = 0;
	utils->pos = get_pos_2(&s, stackb, utils->min_b);
	while (i < utils->pos)
	{
		if (s == 'f')
			stackb = rotate_b(stackb, str);
		else
			stackb = r_rotate_b(stackb, str);
		i++;
	}
	*stacka = push(*stacka, &stackb, str);
	if ((*stacka)->data == utils->min_b && utils->min_b <= utils->max_b)
	{
		*stacka = rotate(*stacka, str);
		utils->min_b++;
	}
	if (get_max(stackb) >= utils->min_prev)
		stackb = add_values_b(stacka, stackb, utils, str);
	while (checking_ifordered(*stacka, 1) != 1)
		*stacka = rotate(*stacka, str);
	return (stackb);
}

t_dlist	*sort500numbers(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	while (ft_tdsize(stacka) > 3)
	{
		stacka = check_last(stacka, stackb, utils, str);
		stacka = separate_stacka(stacka, stackb, utils, str);
		utils->half = (get_max(stacka) + get_min(stacka)) / 2;
	}
	stacka = sort3numbers(stacka, utils, str);
	while (ft_tdsize(*stackb) > 250)
	{
		utils->size = ft_tdsize(stacka);
		utils->max_b = get_max(*stackb);
		utils->min_b = get_max(*stackb) - utils->size;
		utils->min_prev = utils->min_b;
		utils->med_b = utils->max_b - (utils->max_b - utils->min_b) / 2;
		*stackb = add_values_a(&stacka, *stackb, utils, str);
		utils->max_b = get_max(*stackb);
		*stackb = add_values_b(&stacka, *stackb, utils, str);
	}
	*stackb = do_stackb(*stackb, &stacka, str, utils);
	while (checking_ifordered(stacka, 1) != 1)
		stacka = rotate(stacka, str);
	//print_dblist(stacka);
	//print_dblist2(stacka, *stackb);
	return (stacka);
}
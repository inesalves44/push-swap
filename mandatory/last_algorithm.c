/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:52:40 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/14 01:02:58 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	get_values(int data, t_dlist **stackb)
{
	int	a;

	a = 0;
	while (*stackb)
	{
		if ((*stackb)->data < data && (*stackb)->data > a)
			a = (*stackb)->data;
		if (!(*stackb)->next)
			break ;
		(*stackb) = (*stackb)->next;
	}
	while ((*stackb)->prev)
		(*stackb) = (*stackb)->prev;
	return (a);
}

int	check_movements(int data, t_dlist **stackb, t_utils *utils)
{
	int	i;

	i = 0;
	if (data > get_max(*stackb) || data < get_min(*stackb))
	{
		utils->max_b = find_number(*stackb, get_max(*stackb));
		if (utils->max < ft_tdsize(*stackb) / 2)
		{
			i += utils->max_b;
			utils->test_2 = 'f';
		}
		else
		{
			if (utils->max_b == ft_tdsize(*stackb))
				i += 1;
			else	
				i += (ft_tdsize(*stackb) - utils->max_b);
			utils->test_2 = 's';
		}
	}
	else
	{
		utils->save_place = get_values(data, stackb);
		utils->pos = find_number(*stackb, utils->save_place);
		if (utils->pos < ft_tdsize(*stackb) / 2)
		{
			i += utils->pos;
			utils->test_2 = 'f';
		}
		else
		{
			if (utils->pos == ft_tdsize(*stackb))
				i += ft_tdsize(*stackb);
			else
				i += (ft_tdsize(*stackb) - utils->pos);
			utils->test_2 = 's';
		}
	}
	return (i);
}

t_utils	*instructions(t_dlist *stacka, t_dlist **stackb, t_utils *utils)
{
	int	i;

	i = 0;
	utils->movements = 10000;
	while (stacka)
	{
		i = find_number(stacka, stacka->data);
		if (i > ft_tdsize(stacka) / 2)
			i = ft_tdsize(stacka) - i;
		i += check_movements(stacka->data, stackb, utils);
		if (i < utils->movements)
		{
			utils->movements = i;
			utils->value_a = stacka->data;
			utils->pos = find_number(stacka, stacka->data);
			utils->test = 'f';
			if (utils->pos > ft_tdsize(stacka) / 2)
			{
				utils->pos = ft_tdsize(stacka) - utils->pos;
				utils->test = 's';
			}
			if (stacka->data > get_max(*stackb) || stacka->data < get_min(*stackb))
				utils->max_place = 'm';
			else
				utils->max_place = 'l';
		}
		if (i <= 2)
			break ;
		if (!stacka->next)
			break ;
		stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	return (utils);
}

t_dlist	*sort500numbers(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	*stackb = push(*stackb, &stacka, str);
	*stackb = push(*stackb, &stacka, str);
	while (ft_tdsize(stacka) > 3)
	{
		utils = instructions(stacka, stackb, utils);
		while (stacka->data != utils->value_a)
		{
			if (utils->test == 's')
				stacka = r_rotate(stacka, str);
			else
				stacka = rotate(stacka, str);
		}
		//print_dblist2(stacka, *stackb);
		//int a = get_values(stacka->data, stackb);
		if (utils->max_place == 'm' && utils->test_2 == 'f')
			while ((*stackb)->data != get_max(*stackb))
				*stackb = rotate_b(*stackb, str);
		else if (utils->max_place != 'm' && utils->test_2 == 'f')
			while ((*stackb)->data != get_values(stacka->data, stackb))
				*stackb = rotate_b(*stackb, str);
		else if (utils->max_place == 'm' && utils->test_2 == 's')
			while ((*stackb)->data != get_max(*stackb))
				*stackb = r_rotate_b(*stackb, str);
		else if (utils->max_place != 'm' && utils->test_2 == 's')
			while ((*stackb)->data != get_values(stacka->data, stackb))
				*stackb = r_rotate_b(*stackb, str);
		*stackb = push_b(*stackb, &stacka, str);
	}
	print_dblist2(stacka, *stackb);
	return (stacka);
}
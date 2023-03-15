/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:20:05 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/15 17:23:27 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	get_values(int data, t_dlist **stackb)
{
	int	a;

	a = 0;
	if (data > get_max(*stackb) || data < get_min(*stackb))
	{
		a = get_max(*stackb);
		return(a);
	}
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

t_utils	*check_movements(int data, t_dlist *stacka, t_dlist **stackb, t_utils *utils)
{
	int	a;
	int	b;
	int	total_r;
	int	total_rr;
	int	total_other;

	a = 0;
	b = 0;
	while (stacka->prev)
		stacka = stacka->prev;
	a = find_number(stacka, data) - 1;
	b = find_number(*stackb, get_values(data, stackb)) - 1;
	if (b >= a)
		total_r = b;
	else
		total_r = a;
	a = ft_tdsize(stacka) - find_number(stacka, data) + 1;
	b = ft_tdsize(*stackb) - find_number(*stackb, get_values(data, stackb)) + 1;
	if (b >= a)
		total_rr = b;
	else
		total_rr = a;
	if (find_number(stacka, data) < ft_tdsize(stacka) / 2)
	{
		a = find_number(stacka, data) - 1;
		utils->rotate_a = 'y';
	}
	else
	{
		a = ft_tdsize(stacka) - find_number(stacka, data) + 1;
		utils->rotate_a = 'n';
	}
	if (find_number(*stackb, get_values(data, stackb) < ft_tdsize(*stackb) / 2))
	{
		b = find_number(*stackb, get_values(data, stackb)) - 1;
		utils->rotate_b = 'y';
	}
	else
	{
		b = ft_tdsize(*stackb) - find_number(*stackb, get_values(data, stackb)) + 1;
		utils->rotate_b = 'n';
	}
	total_other = a + b;
	if (total_r < total_rr  && total_r < total_other)
	{
		utils->rotate_a = 'y';
		utils->rotate_b = 'y';
		utils->movements_t = total_r;
	}
	else if (total_rr < total_r  && total_rr < total_other)
	{
		utils->rotate_a = 'n';
		utils->rotate_b = 'n';
		utils->movements_t = total_rr;
	}
	else
		utils->movements_t = total_other;
	while (stacka->data != data)
		stacka = stacka->next;
	return (utils);
}

t_utils	*instructions(t_dlist *stacka, t_dlist **stackb, t_utils *utils)
{
	utils->movements_t = 10000;
	while (stacka)
	{
		utils = check_movements(stacka->data, stacka, stackb, utils);
		if ((utils->movements_t) < utils->movements_t_final)
		{
			utils->movements_t_final = utils->movements_t;
			utils->value_a = stacka->data;
			utils->value_b = get_values(stacka->data, stackb);
		}
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
	*stackb = push_b(*stackb, &stacka, str);
	*stackb = push_b(*stackb, &stacka, str);
	while (ft_tdsize(stacka) > 470)
	{
		utils = instructions(stacka, stackb, utils);
		if (utils->rotate_a == 'y' && utils->rotate_b == 'y')
		{
			while (stacka->data != utils->value_a && (*stackb)->data != utils->value_b)
			{
				stacka = rotate(stacka, str);
				*stackb = rotate_b(*stackb, str);
			}
		}
		else if (utils->rotate_a == 'n' && utils->rotate_b == 'n')
		{
			while (stacka->data != utils->value_a && (*stackb)->data != utils->value_b)
			{
				stacka = r_rotate(stacka, str);
				*stackb = r_rotate_b(*stackb, str);
			}
		}
		if (utils->rotate_a == 'y')
			while (stacka->data != utils->value_a)
				stacka = rotate(stacka, str);
		else if (utils->rotate_a == 'n')
			while (stacka->data != utils->value_a)
				stacka = r_rotate(stacka, str);
		if (utils->rotate_b == 'y')
			while ((*stackb)->data != utils->value_b)
				*stackb = rotate_b(*stackb, str);
		else if (utils->rotate_b == 'n')
			while ((*stackb)->data != utils->value_b)
				*stackb = r_rotate_b(*stackb, str);
		*stackb = push_b(*stackb, &stacka, str);
	}
	print_dblist2(stacka, *stackb);
	print_dblist(*stackb);
	return(stacka);
}
/*while (stacka->next)
		stacka = stacka->next;
	while (stacka->data > utils->half)
	{
		while (stacka->prev)
			stacka = stacka->prev;
		stacka = r_rotate(stacka, str);
		*stackb = push_b(*stackb, &stacka, str);
		while (stacka->next)
			stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;*/
/*while (stacka->next)
		stacka = stacka->next;
	while (stacka->data <= utils->quarter)
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
	stacka = separate500quarter(stacka, stackb, utils, str);
	*stackb = do_stackb_2(*stackb, &stacka, utils, str);
	utils->quarter_first = utils->size / 4;
	utils->quarter = utils->half;
	stacka = separate500quarter(stacka, stackb, utils, str);

	*stackb = do_stackb_2(*stackb, &stacka, utils, str);
	while (checking_ifordered(stacka, 1) != 1)
		stacka = rotate(stacka, str);
	utils->quarter_first = utils->half;
	utils->quarter = utils->size - (utils->half / 2);
	*stackb = do_stackb_2(*stackb, &stacka, utils, str);
	while (stacka->data != get_min(stacka))
		stacka = rotate(stacka, str);
	*stackb = do_stackb(*stackb, &stacka, str, utils);
	while (checking_ifordered(stacka, 1) != 1)
		stacka = rotate(stacka, str);*/
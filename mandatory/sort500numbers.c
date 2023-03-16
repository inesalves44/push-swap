/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:20:05 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/16 13:04:41 by idias-al         ###   ########.fr       */
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
	if (total_r <= total_rr  && total_r <= total_other)
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
	utils->movements_t_final = 10000;
	while (stacka)
	{
		utils = check_movements(stacka->data, stacka, stackb, utils);
		if ((utils->movements_t) < utils->movements_t_final)
		{
			utils->movements_t_final = utils->movements_t;
			utils->value_a = stacka->data;
			utils->value_b = get_values(stacka->data, stackb);
			utils->final_rotate_a = utils->rotate_a;
			utils->final_rotate_b = utils->rotate_b;
		}
		if (utils->movements_t_final <= 2)
			break ;
		if (!stacka->next)
			break ;
		stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	return (utils);
}

int	get_values_a(int data, t_dlist *stacka)
{
	int	a;

	a = 700;
	if (data > get_max(stacka) || data < get_min(stacka))
	{
		a = get_min(stacka);
		return(a);
	}
	while (stacka)
	{
		if (stacka->data > data && stacka->data < a)
			a = stacka->data;
		if (!stacka->next)
			break ;
		stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	return (a);
}

t_utils	*check_movements_a(int data, t_dlist **stackb, t_dlist *stacka, t_utils *utils)
{
	int	a;
	int	b;
	int	total_r;
	int	total_rr;
	int	total_other;

	a = 0;
	b = 0;
	while ((*stackb)->prev)
		*stackb = (*stackb)->prev;
	b = find_number(*stackb, data) - 1;
	a = find_number(stacka, get_values_a(data, stacka)) - 1;
	if (b >= a)
		total_r = b;
	else
		total_r = a;
	b = ft_tdsize(*stackb) - find_number(*stackb, data) + 1;
	a = ft_tdsize(stacka) - find_number(stacka, get_values_a(data, stacka)) + 1;
	if (b >= a)
		total_rr = b;
	else
		total_rr = a;
	if (find_number(*stackb, data) < ft_tdsize(*stackb) / 2)
	{
		b = find_number(*stackb, data) - 1;
		utils->rotate_b = 'y';
	}
	else
	{
		b = ft_tdsize(*stackb) - find_number(*stackb, data) + 1;
		utils->rotate_b = 'n';
	}
	if (find_number(stacka, get_values_a(data, stacka) < ft_tdsize(stacka) / 2))
	{
		a = find_number(stacka, get_values_a(data, stacka)) - 1;
		utils->rotate_a = 'y';
	}
	else
	{
		a = ft_tdsize(stacka) - find_number(stacka, get_values_a(data, stacka)) + 1;
		utils->rotate_a = 'n';
	}
	total_other = a + b;
	if (total_r <= total_rr  && total_r <= total_other)
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
	while ((*stackb)->data != data)
		*stackb = (*stackb)->next;
	return (utils);
}

t_utils	*instructions_a(t_dlist *stacka, t_dlist **stackb, t_utils *utils)
{
	utils->movements_t_final = 10000;
	while (*stackb)
	{
		utils = check_movements_a((*stackb)->data, stackb, stacka, utils);
		if ((utils->movements_t) < utils->movements_t_final)
		{
			utils->movements_t_final = utils->movements_t;
			utils->value_a = get_values_a((*stackb)->data, stacka);
			utils->value_b = (*stackb)->data;
			utils->final_rotate_a = utils->rotate_a;
			utils->final_rotate_b = utils->rotate_b;
		}
		if (utils->movements_t_final <= 2)
			break ;
		if (!stacka->next)
			break ;
		stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	return (utils);
}

t_dlist	*test(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	while (ft_tdsize(stacka) > 3)
	{
		utils = instructions(stacka, stackb, utils);
		if (utils->final_rotate_a == 'y' && utils->final_rotate_b == 'y')
		{
			while (stacka->data != utils->value_a && (*stackb)->data != utils->value_b)
			{
				stacka = rotate(stacka, str);
				*stackb = rotate_b(*stackb, str);
			}
		}
		else if (utils->final_rotate_a == 'n' && utils->final_rotate_b == 'n')
		{
			while (stacka->data != utils->value_a && (*stackb)->data != utils->value_b)
			{
				stacka = r_rotate(stacka, str);
				*stackb = r_rotate_b(*stackb, str);
			}
		}
		if (utils->final_rotate_a == 'y')
			while (stacka->data != utils->value_a)
				stacka = rotate(stacka, str);
		else if (utils->final_rotate_a == 'n')
			while (stacka->data != utils->value_a)
				stacka = r_rotate(stacka, str);
		if (utils->final_rotate_b == 'y')
			while ((*stackb)->data != utils->value_b)
				*stackb = rotate_b(*stackb, str);
		else if (utils->final_rotate_b == 'n')
			while ((*stackb)->data != utils->value_b)
				*stackb = r_rotate_b(*stackb, str);
		*stackb = push_b(*stackb, &stacka, str);
	}
	return(stacka);
}

t_dlist	*sort500numbers(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str)
{
	*stackb = push_b(*stackb, &stacka, str);
	*stackb = push_b(*stackb, &stacka, str);
	stacka = test(stacka, stackb, utils, str);
	stacka = sort3numbers(stacka, utils, str);
	while (ft_tdsize(*stackb) > 1)
	{
		utils = instructions_a(stacka, stackb, utils);
		if (utils->final_rotate_a == 'y' && utils->final_rotate_b == 'y')
		{
			while (stacka->data != utils->value_a && (*stackb)->data != utils->value_b)
			{
				stacka = rotate(stacka, str);
				*stackb = rotate_b(*stackb, str);
			}
		}
		else if (utils->final_rotate_a == 'n' && utils->final_rotate_b == 'n')
		{
			while (stacka->data != utils->value_a && (*stackb)->data != utils->value_b)
			{
				stacka = r_rotate(stacka, str);
				*stackb = r_rotate_b(*stackb, str);
			}
		}
		if (utils->final_rotate_a == 'y')
			while (stacka->data != utils->value_a)
				stacka = rotate(stacka, str);
		else if (utils->final_rotate_a == 'n')
			while (stacka->data != utils->value_a)
				stacka = r_rotate(stacka, str);
		if (utils->final_rotate_b == 'y')
			while ((*stackb)->data != utils->value_b)
				*stackb = rotate_b(*stackb, str);
		else if (utils->final_rotate_b == 'n')
			while ((*stackb)->data != utils->value_b)
				*stackb = r_rotate_b(*stackb, str);
		stacka = push(stacka, stackb, str);
	}
	stacka = push_final(stacka, stackb, str);
	if (find_number(stacka, 1) <= ft_tdsize(stacka) / 2)
		while (checking_ifordered(stacka, 1) != 1)
			stacka = rotate(stacka, str);
	else
		while (checking_ifordered(stacka, 1) != 1)
			stacka = r_rotate(stacka, str);
	return(stacka);
}
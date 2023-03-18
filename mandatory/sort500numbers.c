/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:20:05 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/18 21:43:20 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	get_values2(int a, int data, t_dlist **stackb, t_utils *utils)
{
	while (*stackb)
	{
		if ((*stackb)->data < data && (*stackb)->data > a && utils->part == 'f')
			a = (*stackb)->data;
		else if ((*stackb)->data > data && (*stackb)->data < a && utils->part == 's')
			a = (*stackb)->data;
		if (!(*stackb)->next)
			break ;
		(*stackb) = (*stackb)->next;
	}
	while ((*stackb)->prev)
		(*stackb) = (*stackb)->prev;
	return (a);
}

int	get_values(int data, t_dlist **stackb, t_utils *utils)
{
	int	a;

	if (utils->part == 'f')
		a = 0;
	else
		a = 700;
	if ((data > get_max(*stackb) || data < get_min(*stackb)))
	{
		if (utils->part == 'f')
			a = get_max(*stackb);
		else if (utils->part == 's')
			a = get_min(*stackb);
		return(a);
	}
	a = get_values2(a, data, stackb, utils);
	return (a);
}

t_dlist	*test_part2(t_dlist *stacka, t_dlist **stackb, t_utils *utils)
{
	if (utils->part == 'f')
		utils->rotate_total = 'a';
	else
		utils->rotate_total = 'b';
	while (stacka->data != utils->value_a && utils->final_rotate_a == 'y')
		stacka = rotate(stacka, utils);
	while (stacka->data != utils->value_a && utils->final_rotate_a == 'n')
		stacka = r_rotate(stacka, utils);
	if (utils->part == 'f')
		utils->rotate_total = 'b';
	else
		utils->rotate_total = 'a';
	while ((*stackb)->data != utils->value_b && utils->final_rotate_b == 'y')
		*stackb = rotate(*stackb, utils);
	while ((*stackb)->data != utils->value_b && utils->final_rotate_b == 'n')
		*stackb = r_rotate(*stackb, utils);
	*stackb = push(*stackb, &stacka, utils);
	return (stacka);
}

t_dlist	*test(t_dlist *stacka, t_dlist **stackb, t_utils *utils)
{
	utils = instructions(stacka, stackb, utils);
	if (utils->final_rotate_a == 'y' && utils->final_rotate_b == 'y')
	{
		while (stacka->data != utils->value_a && (*stackb)->data != utils->value_b)
		{
			utils->rotate_total = 'y';
			stacka = rotate(stacka, utils);
			*stackb = rotate(*stackb, utils);
			ft_printf("rr\n");
		}
	}
	else if (utils->final_rotate_a == 'n' && utils->final_rotate_b == 'n')
	{
		while (stacka->data != utils->value_a && (*stackb)->data != utils->value_b)
		{
			utils->rotate_total = 'y';
			stacka = r_rotate(stacka, utils);
			*stackb = r_rotate(*stackb, utils);
			ft_printf("rrr\n");
		}
	}
	stacka = test_part2(stacka, stackb, utils);
	if (ft_tdsize(stacka) > 3)
		stacka = test(stacka, stackb, utils);
	return(stacka);
}

t_dlist	*last_three(t_dlist *stacka, t_dlist **stackb, t_utils *utils)
{
	utils->rotate_total = 'a';
	utils->value_b = (*stackb)->data;
	utils->value_a = get_values((*stackb)->data, &stacka, utils);
	if (find_number(stacka, utils->value_a) > ft_tdsize(stacka) / 2)
		while (stacka->data != utils->value_a)
			stacka = r_rotate(stacka, utils);
	else
		while (stacka->data != utils->value_a)
			stacka = rotate(stacka, utils);
	if (ft_tdsize(*stackb) > 1)
		stacka = push(stacka, stackb, utils);
	else
	{
		stacka = push_final(stacka, stackb, utils);
		return (stacka);
	}
	stacka = last_three(stacka, stackb, utils);
	return (stacka);
}

t_dlist	*bigalgorithm(t_dlist *stacka, t_dlist **stackb, t_utils *utils)
{
	*stackb = push(*stackb, &stacka, utils);
	*stackb = push(*stackb, &stacka, utils);
	stacka = test(stacka, stackb, utils);
	utils->rotate_total = 'a';
	if (checking_ifordered(stacka, 1) != 1)
		stacka = sort3numbers(stacka, utils);
	utils->push = 'a';
	utils->part = 's';
	*stackb = test(*stackb, &stacka, utils);
	if (checking_ifordered(*stackb, 2) != 1)
		stacka = sort3numbers_rev(*stackb, utils);
	stacka = last_three(stacka, stackb, utils);
	utils->rotate_total ='a';
	if (find_number(stacka, 1) <= ft_tdsize(stacka) / 2)
		while (checking_ifordered(stacka, 1) != 1)
			stacka = rotate(stacka, utils);
	else
		while (checking_ifordered(stacka, 1) != 1)
			stacka = r_rotate(stacka, utils);
	return(stacka);
}
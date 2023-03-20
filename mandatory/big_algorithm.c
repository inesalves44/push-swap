/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:20:05 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/20 16:19:40 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

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

t_dlist	*test(t_dlist *stacka, t_dlist **stackb, t_utils *u)
{
	u = instructions(stacka, stackb, u);
	if (u->final_rotate_a == 'y' && u->final_rotate_b == 'y')
	{
		while (stacka->data != u->value_a && (*stackb)->data != u->value_b)
		{
			u->rotate_total = 'y';
			stacka = rotate(stacka, u);
			*stackb = rotate(*stackb, u);
			ft_printf("rr\n");
		}
	}
	else if (u->final_rotate_a == 'n' && u->final_rotate_b == 'n')
	{
		while (stacka->data != u->value_a && (*stackb)->data != u->value_b)
		{
			u->rotate_total = 'y';
			stacka = r_rotate(stacka, u);
			*stackb = r_rotate(*stackb, u);
			ft_printf("rrr\n");
		}
	}
	stacka = test_part2(stacka, stackb, u);
	if (ft_tdsize(stacka) > 3)
		stacka = test(stacka, stackb, u);
	return (stacka);
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
		*stackb = sort3numbers_rev(*stackb, utils);
	stacka = last_three(stacka, stackb, utils);
	utils->rotate_total = 'a';
	if (find_number(stacka, 1) <= ft_tdsize(stacka) / 2)
		while (checking_ifordered(stacka, 1) != 1)
			stacka = rotate(stacka, utils);
	else
		while (checking_ifordered(stacka, 1) != 1)
			stacka = r_rotate(stacka, utils);
	return (stacka);
}

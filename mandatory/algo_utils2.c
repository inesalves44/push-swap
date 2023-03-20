/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:28:32 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/20 10:16:06 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	total_moves(int data, t_dlist *stacka, t_dlist **stackb, t_utils *u)
{
	int	a;
	int	b;
	int	moves;

	a = 0;
	b = 0;
	if (u->moves == '1')
	{
		a = find_number(stacka, data) - 1;
		b = find_number(*stackb, get_values(data, stackb, u)) - 1;
	}
	else if (u->moves == '2')
	{
		a = ft_tdsize(stacka) - find_number(stacka, data) + 1;
		b = ft_tdsize(*stackb) - \
		find_number(*stackb, get_values(data, stackb, u)) + 1;
	}
	if (b >= a)
		moves = b;
	else
		moves = a;
	return (moves);
}

int	total_moves_other(int data, t_dlist *sa, t_dlist **sb, t_utils *u)
{
	int	a;
	int	b;

	if (find_number(sa, data) < ft_tdsize(sa) / 2)
	{
		a = find_number(sa, data) - 1;
		u->rotate_a = 'y';
	}
	else
	{
		a = ft_tdsize(sa) - find_number(sa, data) + 1;
		u->rotate_a = 'n';
	}
	if (find_number(*sb, get_values(data, sb, u) < ft_tdsize(*sb) / 2))
	{
		b = find_number(*sb, get_values(data, sb, u)) - 1;
		u->rotate_b = 'y';
	}
	else
	{
		b = ft_tdsize(*sb) - find_number(*sb, get_values(data, sb, u)) + 1;
		u->rotate_b = 'n';
	}
	return (a + b);
}

t_utils	*final_check(t_utils *utils)
{
	if (utils->moves == '1')
	{
		utils->rotate_a = 'y';
		utils->rotate_b = 'y';
	}
	else if (utils->moves == '2')
	{
		utils->rotate_a = 'n';
		utils->rotate_b = 'n';
	}
	return (utils);
}

t_utils	*check_movements(int data, t_dlist *sa, t_dlist **sb, t_utils *u)
{
	char	prev;
	int		moves;

	u->movements_t = 10000;
	u->moves = '1';
	while (sa->prev)
		sa = sa->prev;
	moves = total_moves(data, sa, sb, u);
	u->moves = '2';
	if (moves > total_moves(data, sa, sb, u))
		moves = total_moves(data, sa, sb, u);
	else
		u->moves = '1';
	prev = u->moves;
	u->moves = '3';
	if (moves > total_moves_other(data, sa, sb, u))
		moves = total_moves_other(data, sa, sb, u);
	else
		u->moves = prev;
	u = final_check(u);
	u->movements_t = moves;
	while (sa->data != data)
		sa = sa->next;
	return (u);
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
			utils->value_b = get_values(stacka->data, stackb, utils);
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

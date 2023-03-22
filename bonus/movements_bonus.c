/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:18:44 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/22 10:10:37 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap_bonus.h"

void	rotates(t_dlist **stacka, t_dlist **stackb, char *str, t_utils *utils)
{
	if (!ft_strncmp(str, "ra\n", 3))
		*stacka = rotate(*stacka, utils);
	else if (!ft_strncmp(str, "rb\n", 3))
		*stackb = rotate(*stackb, utils);
	else if (!ft_strncmp(str, "rr\n", 3))
	{
		*stacka = rotate(*stacka, utils);
		*stackb = rotate(*stackb, utils);
	}
}

void	r_rotates(t_dlist **stacka, t_dlist **stackb, char *str, t_utils *utils)
{
	if (!ft_strncmp(str, "rra\n", 4))
		*stacka = r_rotate(*stacka, utils);
	else if (!ft_strncmp(str, "rrb\n", 4))
		*stackb = r_rotate(*stackb, utils);
	else if (!ft_strncmp(str, "rrr\n", 4))
	{
		*stacka = r_rotate(*stacka, utils);
		*stackb = r_rotate(*stackb, utils);
	}
}

void	swap_check(t_dlist **s_a, t_dlist **s_b, char *str, t_utils *utils)
{
	if (!ft_strncmp(str, "sa\n", 3))
		*s_a = swap(*s_a, utils);
	else if (!ft_strncmp(str, "sb\n", 3))
		*s_b = swap(*s_b, utils);
	else if (!ft_strncmp(str, "ss\n", 3))
	{
		*s_a = swap(*s_a, utils);
		*s_b = swap(*s_b, utils);
	}
}

void	push_check(t_dlist **s_a, t_dlist **s_b, char *str, t_utils *utils)
{
	if (!ft_strncmp(str, "pa\n", 3))
		*s_a = push(*s_a, s_b, utils);
	else if (!ft_strncmp(str, "pb\n", 3))
		*s_b = push(*s_b, s_a, utils);
}

t_utils	*start_utils(t_utils *utils, t_dlist *stacka)
{
	utils->rotate_total = 'c';
	utils->push = 'c';
	utils->size = ft_tdsize(stacka);
	utils->movements_t = 0;
	return (utils);
}

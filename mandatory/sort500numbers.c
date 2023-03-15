/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:20:05 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/14 23:41:19 by idias-al         ###   ########.fr       */
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

t_utils	*check_movements(int data, t_dlist **stackb, t_utils *utils)
{
	if (data > get_max(*stackb) || data < get_min(*stackb))
	{
		utils->value_b = get_max(*stackb);
		utils->max_b = find_number(*stackb, get_max(*stackb));
		if (utils->max_b < ft_tdsize(*stackb) / 2)
		{
			utils->movements_b = utils->max_b;
			utils->rotate_b = 'y';
		}
		else
		{
			if (utils->max_b == ft_tdsize(*stackb))
				utils->movements_b = 1;
			else	
				utils->movements_b = (ft_tdsize(*stackb) - utils->max_b);
			if (ft_tdsize(*stackb) == 2)
				utils->rotate_b = 'y';
			utils->rotate_b = 'n';
		}
	}
	else
	{
		utils->value_b = get_values(data, stackb);
		utils->pos = find_number(*stackb, utils->value_b);
		if (utils->pos < ft_tdsize(*stackb) / 2)
		{
			utils->movements_b = utils->pos;
			utils->rotate_b = 'y';
		}
		else
		{
			if (utils->pos == ft_tdsize(*stackb))
				utils->movements_b = ft_tdsize(*stackb);
			else
				utils->movements_b = (ft_tdsize(*stackb) - utils->pos);
			utils->rotate_b = 'n';
		}
	}
	return (utils);
}

t_utils	*instructions(t_dlist *stacka, t_dlist **stackb, t_utils *utils)
{
	utils->movements_t = 10000;
	while (stacka)
	{
		if (stacka->data > utils->half)
		{
			utils->movements_a = find_number(stacka, stacka->data);
			if (utils->movements_a > ft_tdsize(stacka) / 2)
				utils->movements_a = ft_tdsize(stacka) - utils->movements_a;
			utils = check_movements(stacka->data, stackb, utils);
			if ((utils->movements_a + utils->movements_b) < utils->movements_t)
			{
				utils->movements_t = utils->movements_a + utils->movements_b;
				utils->value_a = stacka->data;
				utils->pos = find_number(stacka, stacka->data);
				utils->rotate_a = 'y';
				if (utils->pos > ft_tdsize(stacka) / 2)
				{
					utils->pos = ft_tdsize(stacka) - utils->pos;
					utils->rotate_a = 'n';
				}
			}
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
	while (stacka->next)
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
		stacka = stacka->prev;
	stacka = separte_500a(stacka, stackb, utils, str);
	while (ft_tdsize(*stackb) < 250)
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
	//print_dblist2(stacka, *stackb);
	return(stacka);
}

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
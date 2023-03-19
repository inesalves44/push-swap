/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:47:37 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/19 13:28:49 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	checking_ifordered(t_dlist *lst, int i)
{
	if (lst)
	{
		while (lst->next)
		{
			if (lst->data > lst->next->data && i == 1)
				return (0);
			else if (lst->data < lst->next->data && i == 2)
				return (0);
			lst = lst->next;
		}	
	}
	return (1);
}

int	find_number(t_dlist *stack, int number)
{
	int	i;

	i = 1;
	while (stack->prev)
		stack = stack->prev;
	while (stack)
	{
		if (stack->data == number)
			return (i);
		else if (!stack->next)
			break ;
		stack = stack->next;
		i++;
	}
	return (0);
}

int	get_values2(int a, int data, t_dlist **stackb, t_utils *utils)
{
	while (*stackb)
	{
		if ((*stackb)->data < data && (*stackb)->data > a && utils->part == 'f')
			a = (*stackb)->data;
		else if ((*stackb)->data > data && \
		(*stackb)->data < a && utils->part == 's')
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
		return (a);
	}
	a = get_values2(a, data, stackb, utils);
	return (a);
}

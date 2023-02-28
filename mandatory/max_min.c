/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:15:21 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/28 10:53:14 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	get_max(t_dlist *lst)
{
	int	max;

	max = lst->data;
	while (lst)
	{
		if (lst->data > max)
			max = lst->data;
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	while (lst->prev)
		lst = lst->prev;
	return (max);
}

int	get_min2(t_dlist *lst, int min)
{
	int	min2;

	min2 = get_max(lst);
	while (lst)
	{
		if (lst->data > min && lst->data < min2)
			min2 = lst->data;
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	while (lst->prev)
		lst = lst->prev;
	return (min2);
}

int	get_min(t_dlist *lst)
{
	int	min;

	min = lst->data;
	while (lst)
	{
		if (lst->data < min)
			min = lst->data;
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	while (lst->prev)
		lst = lst->prev;
	return (min);
}

int	get_max2(t_dlist *lst, int max)
{
	int	max2;

	while (lst->prev)
		lst = lst->prev;
	max2 = get_min(lst);
	while (lst)
	{
		if (lst->data < max && lst->data > max2)
			max2 = lst->data;
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	while (lst->prev)
		lst = lst->prev;
	return (max2);
}

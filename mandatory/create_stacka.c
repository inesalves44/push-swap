/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacka.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:05:34 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/21 19:03:08 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist *stack_creation_ind(t_dlist *head)
{
	t_dlist	*lst_temp;

	lst_temp = NULL;
	lst_temp = ft_createnode(1);
	lst_temp->prev = head;
	head->next = lst_temp;
	return (lst_temp);
}

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

t_dlist	*finish_stack(t_dlist *lst, t_dlist *stacka)
{
	int	max;
	int	min;
	int	i;
	int	number;
	int	j;

	max = get_max(lst);
	min = get_min(lst);
	i = 0;
	number = 0;
	j = 0;
	while (lst)
	{
		if (max == lst->data && max != min)
		{
			number = 0;
			max = get_max2(lst, max);
			while (number++ < i)
				stacka = stacka->next;
			stacka->data = ft_tdsize(stacka) - j;
			while (lst->prev)
				lst = lst->prev;
			while (stacka->prev)
				stacka = stacka->prev;
			j++;
			i = 0;
		}
		else if (!lst->next)
			break ;
		else
		{
			lst = lst->next;
			i++;
		}
	}
	return (stacka);
}

t_dlist	*create_stack(t_dlist *lst)
{
	t_dlist	*stacka;
	int		e;
	int		i;
	
	stacka =  NULL;
	e = checking_list(lst);
	if (e == 8000)
		return (NULL);
	i = 1;
	stacka = ft_createnode(1);
	while (i < ft_tdsize(lst))
	{
		stacka->next = stack_creation_ind(stacka);
		stacka = stacka->next;
		i++;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	stacka = finish_stack(lst, stacka);
	return (stacka);
}
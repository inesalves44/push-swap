/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:58:30 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/06 16:28:50 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_dlist	*rotate(t_dlist *lst, int a, char **str)
{
	int		temp;
	char	*str2;

	lst = reorder_stacks(lst);
	temp = lst->data;
	str2 = *str;
	while (lst)
	{
		if (lst->next)
			lst->data = lst->next->data;
		else
		{
			lst->data = temp;
			break ;
		}
		lst = lst->next;
	}
	if (a == 1)
		str2 = ft_strjoin(str2, "ra\n");
	else if (a == 2)
		str2 = ft_strjoin(str2, "rb\n");
	while (lst->prev)
		lst = lst->prev;
	*str = str2;
	return (lst);
}

t_dlist	*r_rotate(t_dlist *lst, int a, char **str)
{
	int		temp;
	char	*str2;

	lst = reorder_stacks(lst);
	str2 = *str;
	while (lst->next)
		lst = lst->next;
	temp = lst->data;
	while (lst)
	{
		if (lst->prev)
			lst->data = lst->prev->data;
		else
		{
			lst->data = temp;
			break ;
		}
		lst = lst->prev;
	}
	if (a == 1)
		str2 = ft_strjoin(str2, "rra\n");
	else if (a == 2)
		str2 = ft_strjoin(str2, "rrb\n");
	while (lst->prev)
		lst = lst->prev;
	*str = str2;
	return (lst);
}

t_dlist	*swap(t_dlist *test, int a, char **str)
{
	int		temp;
	char	*str2;

	str2 = *str;
	test = reorder_stacks(test);
	if (test)
	{
		temp = test->data;
		test->data = test->next->data;
		test->next->data = temp;
		if (a == 1)
			str2 = ft_strjoin(str2, "sa\n");
		else if (a == 2)
			str2 = ft_strjoin(str2, "sb\n");
	}
	while (test->prev)
		test = test->prev;
	*str = str2;
	return (test);
}

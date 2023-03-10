/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:58:30 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/09 13:13:35 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_dlist	*rotate(t_dlist *lst, char **str)
{
	int		temp;
	char	*str2;

	temp = lst->data;
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
	str2 = ft_strdup("ra\n");
	while (lst->prev)
		lst = lst->prev;
	*str = mod_strjoin(*str, str2);
	free(str2);
	return (lst);
}

t_dlist	*rotate_b(t_dlist *lst, char **str)
{
	int		temp;
	char	*str2;

	temp = lst->data;
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
	str2 = ft_strdup("rb\n");
	while (lst->prev)
		lst = lst->prev;
	*str = mod_strjoin(*str, str2);
	free(str2);
	return (lst);
}

t_dlist	*r_rotate(t_dlist *lst, char **str)
{
	int		temp;
	char	*str2;

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
	str2 = ft_strdup("rra\n");
	while (lst->prev)
		lst = lst->prev;
	*str = mod_strjoin(*str, str2);
	free(str2);
	return (lst);
}

t_dlist	*r_rotate_b(t_dlist *lst, char **str)
{
	int		temp;
	char	*str2;

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
	str2 = ft_strdup("rrb\n");
	while (lst->prev)
		lst = lst->prev;
	*str = mod_strjoin(*str, str2);
	free(str2);
	return (lst);
}

t_dlist	*swap(t_dlist *test, char **str2)
{
	int		temp;
	char	*str;

	if (test)
	{
		temp = test->data;
		test->data = test->next->data;
		test->next->data = temp;
		str = ft_strdup("sa\n");
	}
	while (test->prev)
		test = test->prev;
	*str2 = mod_strjoin(*str2, str);
	free(str);
	return (test);
}

t_dlist	*swap_b(t_dlist *test, char **str2)
{
	int		temp;
	char	*str;

	if (test)
	{
		temp = test->data;
		test->data = test->next->data;
		test->next->data = temp;
		str = ft_strdup("sb\n");
	}
	while (test->prev)
		test = test->prev;
	*str2 = mod_strjoin(*str2, str);
	free(str);
	return (test);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:29:05 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/17 17:09:59 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_dlist	*swap(t_dlist *test, t_utils *utils)
{
	int		temp;

	(void)utils;
	if (test)
	{
		temp = test->data;
		test->data = test->next->data;
		test->next->data = temp;
	}
	while (test->prev)
		test = test->prev;
	ft_printf("sa\n");
	return (test);
}

t_dlist	*swap_b(t_dlist *test, t_utils *utils)
{
	int		temp;

	(void)utils;
	if (test)
	{
		temp = test->data;
		test->data = test->next->data;
		test->next->data = temp;
	}
	ft_printf("sb\n");
	while (test->prev)
		test = test->prev;
	return (test);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:34:32 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/22 11:38:20 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_dlist	*swap(t_dlist *test, int a)
{
	t_dlist *lst;
	int		temp;

	lst = test;
	if (test)
	{
		temp = test->data;
		test->data = test->next->data;
		test->next->data = temp;
		lst = test;
		if (a == 1)
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

void	swap_total(t_dlist *stacka, t_dlist *stackb)
{
	t_dlist	*testa;
	t_dlist	*testb;

	testa = stacka;
	testb = stackb;
	stacka = swap(testa, 1);
	stackb = swap(testb, 2);
}
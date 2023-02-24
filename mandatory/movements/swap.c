/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:34:32 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/23 21:25:35 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_dlist	*swap(t_dlist *test, int a)
{
	int		temp;

	test = reorder_stacks(test);
	if (test)
	{
		temp = test->data;
		test->data = test->next->data;
		test->next->data = temp;
		if (a == 1)
			ft_printf("sa\n");
		else
			ft_printf("sb\n");
	}
	while (test->prev)
		test = test->prev;
	return (test);
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
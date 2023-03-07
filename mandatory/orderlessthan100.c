/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderlessthan100.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:05:00 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/07 15:05:45 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist *separte_stacks(t_dlist *stacka, t_dlist **stackb, int size, int high, char **str)
{
	t_dlist	*lstb;
	int		aux2;

	lstb = *stackb;
	aux2 = 0;
	if (stacka->data <= size && high == 0)
	{
		lstb = push(lstb, &stacka, 'b', 'n', str);
		if (lstb->next)
		{
			if (lstb->data <= size / 4 && lstb->next->data > size / 4)
				lstb = rotate(lstb, 2, str);
			else if (lstb->data <= (size / 4 * 3) && lstb->next->data > (size / 4 * 3))
				lstb = swap(lstb, 2, str);
		}
		*stackb = lstb;
		aux2 = 1;
	}
	else if (stacka->data > size && high == 1)
	{
		lstb = push(lstb, &stacka, 'b', 'n', str);
		if (lstb->next)
		{
			if (lstb->data < (size + size / 4) && lstb->next->data > (size + size / 4))
				lstb = rotate(lstb, 2, str);
			else if (lstb->data <= (size + size / 4 * 3) && lstb->next->data > (size + size / 4 * 3))
				lstb = swap(lstb, 2, str);
		}
		*stackb = lstb;
		aux2 = 1;
	}
	if (aux2 == 0)
		stacka = rotate(stacka, 1, str);
	while (stacka)
	{
		if (stacka->data <= size && high == 0)
			break ;
		else if (stacka->data > size && high == 1)
			break ;
		else if (!stacka->next)
			return (stacka);
		stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	stacka = separte_stacks(stacka, stackb, size, high, str);
	return(stacka);
}

int	get_pos(int max, int min, int size, char *test)
{
	char	s;
	int		pos;
	
	if (min > size - min)
	{
		pos = size - min + 1;
		s = 's';
	}
	else
	{
		pos = min - 1;
		s = 'f';
	}
	if (pos > size - max)
	{
		pos = size - max + 1;
		s = 's';
	}
	else if (pos >= max)
	{
		pos = max - 1;
		s = 'f';
	}
	*test = s;
	return (pos);
}

t_dlist	*do_stackb(t_dlist *stackb, t_dlist **stacka, char **str)
{
	int		pos;
	int		min;
	int		max;
	char	*a;
	t_dlist	*lsta;
	
	lsta = *stacka;
	if (ft_tdsize(stackb) == 1)
	{
		lsta = push(lsta, &stackb, 'a', 'f', str);
		*stacka = lsta;
		return (stackb);
	}
	min = get_min(stackb);
	max = get_max(stackb);
	char test = 'a';
	a = &test;
	int posmin = find_number(stackb, min);
	int posmax = find_number(stackb, max);
	int size = ft_tdsize(stackb);
	pos = get_pos(posmax, posmin, size, a);
	test = *a;
	int i = 0;
	while (i < pos)
	{
		if (test == 'f')
			stackb = rotate(stackb, 2, str);
		else
			stackb = r_rotate(stackb, 2, str);
		i++;
	}
	lsta = push(lsta, &stackb, 'a', 'n', str);
	if (min == lsta->data)
		lsta = rotate(lsta, 1, str);
	*stacka = lsta;
	stackb = do_stackb(stackb, stacka, str);
	return (stackb);
}

t_dlist	*sortless100numbers(t_dlist *stacka, t_dlist **stackb, char **str)
{
	t_dlist	*lstb;
	int		size;

	if (ft_tdsize(stacka) % 2 == 0)
		size = ft_tdsize(stacka) / 2;
	else
		size = ft_tdsize(stacka) / 2 + 1;
	lstb = *stackb;
	while (stacka->next)
		stacka = stacka->next;
	while (stacka->data <= size)
	{
		while (stacka->prev)
			stacka = stacka->prev;
		print_dblist(stacka);
		stacka = r_rotate(stacka, 1, str);
		print_dblist(stacka);
		lstb = push(lstb, &stacka, 'b', 'n', str);
		while (stacka->next)
			stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	print_dblist2(stacka, lstb);
	stacka = separte_stacks(stacka, stackb, size, 0, str);
	while (stacka->prev)
		stacka = stacka->prev;
	lstb = *stackb;
	lstb = do_stackb(lstb, &stacka, str);
	*stackb = lstb;
	stacka = separte_stacks(stacka, stackb, size, 1, str);
	while (stacka->prev)
		stacka = stacka->prev;
	lstb = *stackb;
	lstb = do_stackb(lstb, &stacka, str);
	while (checking_ifordered(stacka, 1) != 1)
		stacka = rotate(stacka, 1, str);
	return (stacka);
}
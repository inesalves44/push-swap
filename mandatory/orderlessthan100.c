/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderlessthan100.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:05:00 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/02 22:10:47 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist *separte_stacks(t_dlist *stacka, t_dlist **stackb, int size, int high)
{
	t_dlist	*lstb;
	int		aux2;

	lstb = *stackb;
	aux2 = 0;
	if (stacka->data <= size && high == 0)
	{
		lstb = push(lstb, &stacka, 'b', 'n');
		if (lstb->data == get_min(lstb) && lstb->next)
			lstb = rotate(lstb, 2);
		*stackb = lstb;
		aux2 = 1;
	}
	else if (stacka->data > size && high == 1)
	{
		lstb = push(lstb, &stacka, 'b', 'n');
		if (lstb->data == get_min(lstb) && lstb->next)
			lstb = rotate(lstb, 2);
		*stackb = lstb;
		aux2 = 1;
	}
	if (aux2 == 0)
		stacka = rotate(stacka, 1);
	//print_dblist2(stacka, lstb);
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
	stacka = separte_stacks(stacka, stackb, size, high);
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

t_dlist	*do_stackb(t_dlist *stackb, t_dlist **stacka)
{
	int		pos;
	int		min;
	int		max;
	char	*a;
	t_dlist	*lsta;
	
	lsta = *stacka;
	if (ft_tdsize(stackb) == 1)
	{
		lsta = push(lsta, &stackb, 'a', 'f');
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
		//print_dblist2(lsta, stackb);
		if (test == 'f')
			stackb = rotate(stackb, 2);
		else
			stackb = r_rotate(stackb, 2);
		i++;
	}
	lsta = push(lsta, &stackb, 'a', 'n');
	if (min == lsta->data)
		lsta = rotate(lsta, 1);
	*stacka = lsta;
	stackb = do_stackb(stackb, stacka);
	return (stackb);
}

t_dlist	*sortless100numbers(t_dlist *stacka, t_dlist **stackb)
{
	t_dlist	*lstb;
	int		size;

	if (ft_tdsize(stacka) % 2 == 0)
		size = ft_tdsize(stacka) / 2;
	else
		size = ft_tdsize(stacka) / 2 + 1;
	stacka = separte_stacks(stacka, stackb, size, 0);
	while (stacka->prev)
		stacka = stacka->prev;
	lstb = *stackb;
	//print_dblist2(stacka, lstb);
	lstb = do_stackb(lstb, &stacka);
	*stackb = lstb;
	stacka = separte_stacks(stacka, stackb, size, 1);
	while (stacka->prev)
		stacka = stacka->prev;
	lstb = *stackb;
	//print_dblist2(stacka, lstb);
	lstb = do_stackb(lstb, &stacka);
	while (checking_ifordered(stacka, 1) != 1)
		stacka = rotate(stacka, 1);
	//print_dblist(stacka);
	return (stacka);
}
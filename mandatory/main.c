/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:56:25 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/02 01:12:10 by idias-al         ###   ########.fr       */
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
	while (stack)
	{
		if (stack->data == number)
			return (i);
		else if (!stack->next)
			break ;
		stack = stack->next;
		i++;
	}
	return (ft_tdsize(stack));
}

t_dlist *separte_stacks(t_dlist *stacka, t_dlist **stackb, int size, int high)
{
	t_dlist	*lstb;
	int		aux2;

	lstb = *stackb;
	aux2 = 0;
	if (stacka->data <= size && high == 0)
	{
		lstb = pushing_to_stack(stacka, lstb, 2);
		stacka = deletefromstack(stacka, 2, 2);
		*stackb = lstb;
		aux2 = 1;
	}
	else if (stacka->data > size && high == 1)
	{
		lstb = pushing_to_stack(stacka, lstb, 2);
		stacka = deletefromstack(stacka, 2, 2);
		*stackb = lstb;
		aux2 = 1;
	}
	if (aux2 == 0)
		stacka = rotate(stacka, 1);
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

int	get_pos(int max, int min, int size)
{
	if (max > size / 2 && min > size / 2)
	{
		if (max > min)
			size = size - max;
		else
			size = size - min;
	}
	else if (max > size / 2 && min > size / 2)
	{
		if (max < min)
			size = max;
		else
			size = min;
	}
	else if (max > size / 2 && min < size / 2)
	{
		if (size - max < min)
			size = size - max;
		else
			size = min;
	}
	else if (max < size / 2 && min > size / 2)
	{
		if (size - min < max)
			size = size - min;
		else
			size = max;
	}
	return (size);
}

t_dlist	*do_stackb(t_dlist *stackb, t_dlist **stacka)
{
	int size;
	int	min;
	int max;
	t_dlist	*lsta;
	
	lsta = *stacka;
	min = get_min(stackb);
	max = get_max(stackb);
	size = get_pos(find_number(stackb, max), find_number(stackb, min), ft_tdsize(stackb));
	int i = 0;
	while (i < size)
	{
		if (size > ft_tdsize(stackb))
			stackb = rotate(stackb, 2);
		else
			stackb = r_rotate(stackb, 2);
		i++;
	}
	lsta = pushing_to_stack(stackb, lsta, 2);
	stackb = deletefromstack(stackb, 2, 1);
	if (min == lsta->data)
		lsta = rotate(lsta, 1);
	else
		if (lsta->data > lsta->next->data && lsta->next->data > min)
			lsta = swap(lsta, 1);
	*stacka = lsta;
	if (ft_tdsize(stackb) > 2)
		stackb = do_stackb(stackb, stacka);
	return (stackb);
}

t_dlist	*sort100numbers(t_dlist *stacka, t_dlist **stackb)
{
	t_dlist	*lstb;
	int		size;

	size = ft_tdsize(stacka) / 2;
	stacka = separte_stacks(stacka, stackb, size, 0);
	while (stacka->prev)
		stacka = stacka->prev;
	lstb = *stackb;
	lstb = do_stackb(lstb, &stacka);
	print_dblist(lstb);
	print_dblist(stacka);
	/*int max = get_max(lstb);
	int min = get_min(lstb);
	int i = 0;
	while (i < 2)
	{
		if (lstb->data == max)
		{
			stacka = pushing_to_stack(lstb, stacka, 2);
			lstb = deletefromstack(lstb, 2, 1);
			if (stacka->data > stacka->next->data)
				stacka = swap(stacka, 1);
		}
		else if (lstb->data == min)
		{
			stacka = pushing_to_stack(lstb, stacka, 2);
			lstb = deletefromstack(lstb, 2, 1);
			stacka = rotate(stacka, 1);
		}
		i++;
	}
	lstb = deletefromb(lstb);
	*stackb = lstb;
	stacka = separte_stacks(stacka, stackb, size, 1);
	while (stacka->prev)
		stacka = stacka->prev;
	lstb = *stackb;
	lstb = do_stackb(lstb, &stacka);
	i = 0;
	max = get_max(lstb);
	min = get_min(lstb);
	stacka = rotate(stacka, 2);
	stacka = rotate(stacka, 2);
	if (lstb->data > lstb->next->data)
		lstb = swap(lstb, 2);
	while (i < 2)
	{
		stacka = pushing_to_stack(lstb, stacka, 2);
		lstb = deletefromstack(lstb, 2, 1);
		stacka = rotate(stacka, 2);
		i++;
	}
	lstb = deletefromb(lstb);*/
	return (stacka);
}

t_dlist	*annalysing_stack(t_dlist *stacka, t_dlist **stackb)
{
	if (checking_ifordered(stacka, 1) == 1)
	{
		free_list(&stacka);
		exit(EXIT_SUCCESS);
	}
	if (ft_tdsize(stacka) < 3)
		stacka = swap(stacka, 1);
	else if (ft_tdsize(stacka) < 4)
		stacka = sort3numbers(stacka);
	else if (ft_tdsize(stacka) < 6)
		stacka = sort5numbers(stacka, stackb);
	else if (ft_tdsize(stacka) < 101)
		stacka = sort100numbers(stacka, stackb);
	return (stacka);
}

int	main(int argc, char *argv[])
{
	t_dlist	*lst;
	t_dlist	*stacka;
	t_dlist	*stackb;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	lst = first_list(argv, argc);
	while (lst->prev)
		lst = lst->prev;
	stacka = create_stack(lst);
	free_list(&lst);
	if (!stacka)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	stackb = NULL;
	stacka = annalysing_stack(stacka, &stackb);
	//stacka = pushing_toa(stacka, stackb);
	//stackb = deletefromb(stackb);
	//print_dblist(stacka);
	//free_list(&stacka);
	return (0);
}

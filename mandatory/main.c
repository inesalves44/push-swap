/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:56:25 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/03 15:15:04 by idias-al         ###   ########.fr       */
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
	return (0);
}

/*t_dlist *separte_stacks2(t_dlist *stacka, t_dlist **stackb, int size)
{
	t_dlist	*lstb;
	int		aux2;

	lstb = *stackb;
	aux2 = 0;
	while (stacka->prev)
		stacka = stacka->prev;
	if (stacka->data <= size)
	{
		lstb = push(lstb, &stacka, 'b', 'n');
		*stackb = lstb;
		aux2 = 1;
	}
	if (aux2 == 0)
		stacka = rotate(stacka, 1);
	while (stacka)
	{
		if (stacka->data <= size)
			break ;
		else if (!stacka->next)
			return (stacka);
		stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	stacka = separte_stacks2(stacka, stackb, size);
	return(stacka);
}

t_dlist	*do_stacka2(t_dlist *stacka, t_dlist **stackb, t_dlist **temp)
{
	t_dlist	*lstb;
	t_dlist	*aux;
	int		size;

	lstb = *stackb;
	aux = *temp;
	if (ft_tdsize(stacka) % 2 == 0)
		size = ft_tdsize(stacka) / 2 + aux->data;
	else
		size = ft_tdsize(stacka) / 2 + 1 + aux->data;
	if (aux->data == 0)
		aux = ft_createnode(size);
	else
	{
		aux->prev = ft_createnode(size);
		aux->prev->next = aux;
		aux = aux->prev;
	}
	if(stacka->data <= size)
		lstb = push(lstb, &stacka, 'b', 'n');
	while (stacka)
	{
		if (!stacka->next)
			break ;
		stacka = stacka->next;
	}
	if(stacka->data <= size)
	{	
		while (stacka->prev)
			stacka = stacka->prev;
		stacka = r_rotate(stacka, 1);
		lstb = push(lstb, &stacka, 'b', 'n');
	}
	while (stacka->prev)
		stacka = stacka->prev;
	//print_dblist2(stacka,lstb);
	*stackb = lstb;
	stacka = separte_stacks2(stacka, stackb, size);
	while (stacka->prev)
		stacka = stacka->prev;
	//print_dblist2(stacka, *stackb);
	//print_dblist(aux);
	if (checking_ifordered(stacka, 1) == 1)
		return (stacka);
	if (ft_tdsize(stacka) > 3)
		stacka = do_stacka2(stacka, stackb, &aux);
	while(aux->prev)
		aux = aux->prev;
	*temp = aux;
	stacka = sort3numbers(stacka);
	return (stacka);
}

t_dlist	*test(t_dlist **stacka, t_dlist *stackb, t_dlist **temp, int i, int help)
{
	t_dlist	*aux;
	t_dlist	*lsta;
	int		mid;

	lsta = *stacka;
	aux = *temp;
	if (aux->next)
	{
		if (get_max(stackb) % 2 == 0)
			mid = (get_max(stackb) - aux->next->data) / 2;
		else
			mid = (get_max(stackb) - aux->next->data) / 2 + 1;
	}
	else
	{
		if (get_max(stackb) % 2 == 0)
			mid = get_max(stackb) / 2;
		else
			mid = get_max(stackb) / 2 + 1;
	}
	if (stackb->data > mid)
		lsta = push(lsta, &stackb, 'a', 'n');
	else
	{
		while (stackb->data < mid && help++)
			stackb = rotate(stackb, 2);
	}
	*stacka = lsta;
	if (aux->next && aux->next->data == get_max(stackb))
	{
		aux = deletefromstack(aux);
		stackb = test(stacka, stackb, 0, 0);
	}
	*temp = aux;
	return (stackb);
}

t_dlist	*do_stackb2(t_dlist **stacka, t_dlist *stackb, t_dlist **temp)
{
	stackb = test(stacka, stackb, temp, 0, 0);
	
	return (stackb);
}

t_dlist	*sort100numbers(t_dlist *stacka, t_dlist **stackb)
{
	t_dlist	*temp;

	temp = ft_createnode(0);
	stacka = do_stacka2(stacka, stackb, &temp);
	print_dblist2(stacka, *stackb);
	print_dblist(temp);
	/**stackb = do_stackb2(&stacka, *stackb, &temp);
	print_dblist2(stacka, *stackb);
	print_dblist(temp);
	*stackb = do_stackb2(&stacka, *stackb, &temp);
	*stackb = do_stackb2(&stacka, *stackb, &temp);
	print_dblist2(stacka, *stackb);
	print_dblist(temp);
	*stackb = do_stackb2(&stacka, *stackb, &temp);
	print_dblist2(stacka, *stackb);
	print_dblist(temp);
	return (stacka);
}*/

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
	else if (ft_tdsize(stacka) <= 100)
		stacka = sortless100numbers(stacka, stackb);
	//else if (ft_tdsize(stacka) <= 100)
	//	stacka = sort100numbers(stacka, stackb);
	//printf("%d\n", ft_tdsize(stacka));
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
	free_list(&stacka);
	return (0);
}

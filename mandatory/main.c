/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:56:25 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/01 16:21:57 by idias-al         ###   ########.fr       */
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

t_dlist	*pass_to_a(t_dlist *stackb, t_dlist **stacka, int size)
{
	int		i;
	int		j;
	t_dlist	*lsta;

	lsta = *stacka;
	i = 0;
	j = find_maxnumberi(stackb);
	print_dblist(stackb);
	if (j > (ft_tdsize(stackb) / 2))
	{
		while (i < size)
		{
			stackb = r_rotate(stackb, 2);
			if (i > 0 && stackb->data < stackb->next->data)
				stackb = swap(stackb, 2);
			i++;
		}
	}
	i = 0;
	while (i < size)
	{
		if (lsta->data < stackb->data)
		{
			lsta = rotate(lsta, 1);
			lsta = pushing_to_stack(stackb, lsta, 2);
			stackb = deletefromstack(stackb, 2, 1);
			lsta = r_rotate(lsta, 1);
		}
		if (stackb->data > stackb->next->data)
		{
			lsta = pushing_to_stack(stackb, lsta, 2);
			stackb = deletefromstack(stackb, 2, 1);
		}
		else
		{
			stackb = swap(stackb, 2);
			if (i == 0)
				i = 0;
			else
				i--;
		}
		i++;
	}
	while (lsta->prev)
		lsta = lsta->prev;
	*stacka = lsta;
	return (stackb);
}

int	find_maxnumberi(t_dlist *stackb)
{
	int	i;

	i = 1;
	while (stackb)
	{
		if (stackb->data == get_max(stackb))
			return (i);
		else if (!stackb->next)
			break ;
		stackb = stackb->next;
		i++;
	}
	return (ft_tdsize(stackb));
}

t_dlist *separte_stacks(t_dlist *stacka, t_dlist **stackb, int size, int size2, int size3, int aux)
{
	t_dlist	*lstb;
	int		aux2;
	static int temp;

	lstb = *stackb;
	aux2 = 0;
	if(size3 == ft_tdsize(stacka))
		temp = 0;
	if (stacka->data <= size)
	{
		lstb = pushing_to_stack(stacka, lstb, 2);
		stacka = deletefromstack(stacka, 2, 2);
		if (lstb->next && aux == 0)
		{
			if (lstb->data == get_min(lstb))
				lstb = rotate(lstb, 2);
			else if (lstb->data > get_min(lstb))
			{
				lstb = r_rotate(lstb, 2);
				lstb = swap(lstb, 2);
				lstb = rotate(lstb, 2);
				lstb = rotate(lstb, 2);
			}
		}
		else if (lstb->next && aux != 0)
		{
			if (temp == 0)
				lstb = rotate(lstb, 2);
			else
			{
				lstb = r_rotate(lstb, 2);
				lstb = swap(lstb, 2);
				lstb = rotate(lstb, 2);
				lstb = rotate(lstb, 2);
			}	
		}
		*stackb = lstb;
		temp++;
		aux2 = 1;
	}
	else if (stacka->data <= size2)
	{
		lstb = pushing_to_stack(stacka, lstb, 2);
		stacka = deletefromstack(stacka, 2, 2);
		if (lstb->next)
		{
			if (lstb->data < get_max(lstb))
			{
				lstb = swap(lstb, 2);
				lstb = rotate(lstb, 2);
				if (lstb->data < lstb->next->data)
					lstb = swap(lstb, 2);
				lstb = r_rotate(lstb, 2);
			}
		}
		*stackb = lstb;
		aux2 = 1;
	}
	if (aux2 == 0)
		stacka = rotate(stacka, 1);
	while (stacka)
	{
		if (stacka->data <= size2)
			break ;
		else if (!stacka->next)
			return (stacka);
		stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	stacka = separte_stacks(stacka, stackb, size, size2, size3, aux);
	return(stacka);
}

t_dlist	*do_stacka(t_dlist *stacka, t_dlist **stackb, int aux)
{
	int	size;
	int	size2;

	size = ft_tdsize(stacka) / 3 + get_min(stacka);
	size2 = (ft_tdsize(stacka) / 3) * 2 + get_min(stacka);
	int size3 = ft_tdsize(stacka);
	stacka = separte_stacks(stacka, stackb, size, size2, size3, aux);
	while (stacka->prev)
		stacka = stacka->prev;
	if (checking_ifordered(stacka, 1) == 0 && ft_tdsize(stacka) > 3)
		stacka = do_stacka(stacka, stackb, size);
	else if (checking_ifordered(stacka, 1) == 0 && ft_tdsize(stacka) == 3)
		stacka = sort3numbers(stacka);
	if (checking_ifordered(stacka, 1) == 0)
		stacka = do_stacka(stacka, stackb, size);
	return (stacka);
}

t_dlist	*do_stackb(t_dlist *stackb, t_dlist **stacka)
{
	int size = ft_tdsize(*stacka);
	
	stackb = pass_to_a(stackb, stacka, size);
	stackb = pass_to_a(stackb, stacka, size + 1);
	print_dblist(stackb);
	print_dblist(*stacka);
	/*if (ft_tdsize(stackb) > 3)
		stackb = do_stackb(stackb, stacka);
	else
		stackb = sort3numbers_rev(stackb);
	if (checking_ifordered(stackb, 2) == 0)
		stackb = do_stackb(stackb, stacka);*/
	return (stackb);
}

t_dlist	*sort100numbers(t_dlist *stacka, t_dlist **stackb)
{
	t_dlist	*lstb;

	stacka = do_stacka(stacka, stackb, 0);
	lstb = *stackb;
	lstb = do_stackb(lstb, &stacka);
	*stackb = lstb;
	//print_dblist(*stackb);
	//print_dblist(stacka);
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

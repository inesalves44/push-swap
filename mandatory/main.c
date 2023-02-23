/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:56:25 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/23 15:48:25 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	checking_ifordered(t_dlist *stacka)
{
	t_dlist	*lst;
	int		a;

	lst = stacka;
	a = 0;
	while (lst->next)
	{
		if (lst->data > lst->next->data)
			a++;
		lst = lst->next;
	}
	while (lst->prev)
		lst = lst->prev;
	return (a);
}


int	checking_ifordered_b(t_dlist *stackb)
{
	t_dlist	*lst;
	int		a;

	lst = stackb;
	a = 0;
	while (lst->next)
		lst = lst->next;
	while (lst->prev)
	{
		if (lst->data > lst->prev->data)
			a++;
		lst = lst->prev;
	}
	return (a);
}

t_dlist	*check_test(t_dlist *lsta, int size)
{
	int	temp;

	temp = 1;
	while (lsta->prev)
		lsta = lsta->prev;
	while (lsta)
	{
		if ((lsta->data == size || lsta->data ==  (size - 1)))
		{
			if (temp == 1)
			{
				lsta = rotate(lsta, 1);
				lsta = check_test(lsta, size);
			}
			else if (temp == 2)
			{
				while (lsta->prev)
					lsta = lsta->prev;
				lsta = swap(lsta, 1);
				lsta = rotate(lsta, 1);
				lsta = check_test(lsta, size);
			}
		}
		if (!lsta->next)
			break ;
		lsta = lsta->next;
		temp++;
	}
	while (lsta->prev)
		lsta = lsta->prev;
	return (lsta);
}


void	sort5numbers(t_dlist *stacka, t_dlist *stackb)
{
	int	size;

	stackb = NULL;
	size = ft_tdsize(stacka);
	stacka = check_test(stacka, size);
	print_dblist(stacka);
	/*if (ft_tdsize(stacka) == 5)
		stacka = checking_a(stacka);
	if (!checking_ifordered(stacka))
		exit(EXIT_SUCCESS);
	stackb = pushing_tob(stacka, stackb, ft_tdsize(stacka));
	stacka = deletefroma(stacka, ft_tdsize(stacka));
	checking_ifordered(stacka);
	if (checking_ifordered(stacka) != 0 && ft_tdsize(stacka) > 2)
		stacka = sort3numbers(stacka, &stackb);
	else if (checking_ifordered(stacka) != 0 && ft_tdsize(stacka) == 2)
		stacka = swap(stacka, 1);
	reorder_stacks(&stacka, &stackb);
	if (checking_ifordered_b(stackb) != 0 && ft_tdsize(stackb) <= 2)
		stackb = swap(stackb, 2);
	else if (checking_ifordered_b(stackb) != 0 && ft_tdsize(stackb) > 2)
		stackb = sort3numbers_rev(stackb, stacka);
	reorder_stacks(&stacka, &stackb);
	if (min_values(&stackb) < stacka->data)
	{
		stackb = pushing_tob(stacka, stackb, ft_tdsize(stacka));
		stacka = deletefroma(stacka, ft_tdsize(stacka));
		if (checking_ifordered_b(stackb) != 0)
			stackb = sort3numbers_rev(stackb, stacka);
		reorder_stacks(&stacka, &stackb);
	}
	stacka = pushing_toa(stacka, stackb);
	stackb = deletefromb(stackb);*/
}

void	annalysing_stack(t_dlist *stacka)
{
	t_dlist	*stackb;
	t_dlist	*lst;

	stackb = NULL;
	lst = stacka;
	if (checking_ifordered(stacka) == 0)
	{
		free_list(&stacka);
		exit(EXIT_SUCCESS);
	}
	if (ft_tdsize(stacka) < 3)
		stacka = swap(lst, 1);
	else if (ft_tdsize(stacka) < 4)
		sort3numbers(stacka, &stackb);
	else if (ft_tdsize(stacka) < 6)
		sort5numbers(stacka, stackb);
}

int	main(int argc, char *argv[])
{
	t_dlist	*lst;
	t_dlist	*stacka;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	lst = firt_list(argv, argc);
	while (lst->prev)
		lst = lst->prev;
	stacka = create_stack(lst);
	if (!stacka)
	{
		ft_printf("Error\n");
		free_list(&lst);
		exit(EXIT_FAILURE);
	}
	annalysing_stack(stacka);
	free_list(&stacka);
	return (0);
}

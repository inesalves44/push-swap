/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:56:25 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/22 18:11:31 by idias-al         ###   ########.fr       */
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

int	check_max5(t_dlist *lsta)
{
	t_dlist	*stacka;
	int		temp;
	int		a;
	int		b;

	stacka = lsta;
	temp = 1;
	while (lsta)
	{
		if (lsta->data == 5)
			a = temp;
		if (lsta->data == 4)
			b = temp;
		lsta = lsta->next;
		temp++;
	}
	lsta = stacka;
	if (a == 2 && b == 1)
		return (1);
	else if (a == 1 && b == 2)
		return (2);
	else if ((a == 1 && b == 3) || (a == 3 && b == 1) || (a == 2 && b == 3) || (a == 3 && b == 2))
		return (3);
	else if ((a == 1 && b > 3) || (a > 3 && b == 1))
		return (4);
	else if (a == 2 || b == 2)
		return (6);
	return (7);
}

int	check_max4(t_dlist *lsta)
{
	t_dlist	*stacka;
	int		temp;
	int		a;
	int		b;

	stacka = lsta;
	temp = 1;
	while (lsta)
	{
		if (lsta->data == 3)
			a = temp;
		if (lsta->data == 4)
			b = temp;
		lsta = lsta->next;
		temp++;
	}
	lsta = stacka;
	if (a == 2 && b == 1)
		return (1);
	else if (a == 1 && b == 2)
		return (2);
	else if ((a == 1 && b == 3) || (a == 3 && b == 1) || (a == 2 && b == 3) || (a == 3 && b == 2))
		return (3);
	else if ((a == 1 && b > 3) || (a > 3 && b == 1))
		return (4);
	else if (a == 2 || b == 2)
		return (6);
	return (7);
}

t_dlist	*checking_a(t_dlist *lsta)
{
	t_dlist	*stacka;
	int		a;

	stacka = lsta;
	if (ft_tdsize(lsta) == 5)
		a = check_max5(lsta);
	else
		a = check_max4(lsta);
	if (a != 3 && a != 7)
	{
		if (a == 2 || a == 6)
			stacka = swap(lsta, 1);
		stacka = rotate(stacka, 1);
		if (a == 2 || a == 3)
			stacka = rotate(stacka, 1);
	}
	else if (a == 3)
	{
		stacka = r_rotate(stacka, 1);
		stacka = r_rotate(stacka, 1);
	}
	reorder_stacks(&stacka, NULL);
	return(stacka);
}

int	min_values(t_dlist **stackb)
{
	t_dlist	*lstb;
	int		min;

	lstb = *stackb;
	min = lstb->data;
	while (lstb->next)
	{
		if (min > lstb->next->data)
			min = lstb->next->data;
		lstb = lstb->next;
	}
	reorder_stacks(stackb, NULL);
	return (min);
}

/*int	max_values(t_dlist **stackb)
{
	t_dlist	*lstb;
	int		max;

	lstb = *stackb;
	max = lstb->data;
	while (lstb->next)
	{
		if (max < lstb->next->data)
			max = lstb->next->data;
		lstb = lstb->next;
	}
	reorder_stacks(stackb, NULL);
	return (max);
}*/

void	sort5numbers(t_dlist *stacka, t_dlist *stackb)
{
	stackb = NULL;
	if (ft_tdsize(stacka) == 5)
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
	stackb = deletefromb(stackb);
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

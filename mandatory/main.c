/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:56:25 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/21 19:25:22 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	checking_lastcase(t_dlist *stacka, t_dlist *stackb)
{
	t_dlist *lsta;
	t_dlist *lstb;
	t_dlist *node;
	int		temp;

	lsta = stacka;
	if (stackb)
		lstb = stackb;
	else
		lstb = NULL;
	temp = lsta->data;
	node = ft_createnode(temp);
	stackb = insert_node(lstb, node);
	lstb = stackb;
	ft_printf("pb\n");
	stacka = delete_node(lsta);
	lsta = stacka;
	stacka = swap(lsta, 1);
	lsta = stacka;
	temp = lstb->data;
	node = ft_createnode(temp);
	stacka = insert_node(lsta, node);
	stackb = delete_node(lstb);
	ft_printf("pa\n");
}

t_dlist	*sort3numbers(t_dlist *stacka, t_dlist *stackb)
{
	t_dlist	*lst;

	if (!stackb)
		stackb = NULL;
	lst = stacka;
	if (lst->data < lst->next->data && lst->data > lst->next->next->data)
	{
		stacka = r_rotate(lst, 1);
		return (stacka);
	}
	else if (lst->data > lst->next->data)
	{
		if (lst->data > lst->next->next->data && lst->next->next)
			rotate(stacka, 1);
		lst = stacka;
		if (lst->data > lst->next->data)
			stacka = swap(lst, 1);
		return (stacka); 
	}
	else if (lst->next->data > lst->next->next->data)
		checking_lastcase(stacka, stackb);
	return (stacka);
}

void	checking_lastcase_rev(t_dlist *stacka, t_dlist *stackb)
{
	t_dlist *lsta;
	t_dlist *lstb;
	t_dlist *node;
	int		temp;

	lsta = stacka;
	lstb = stackb;
	temp = lstb->data;
	node = ft_createnode(temp);
	stacka = insert_node(lsta, node);
	lsta = stacka;
	ft_printf("pa\n");
	stackb = delete_node(lstb);
	lstb = stackb;
	stackb = swap(lstb, 0);
}

t_dlist	*sort3numbers_rev(t_dlist *stackb, t_dlist *stacka)
{
	t_dlist	*lst;

	lst = stackb;
	if (lst->data > lst->next->data && lst->data < lst->next->next->data)
		stackb = r_rotate(lst, 0);
	else if (lst->data < lst->next->data)
	{
		if (lst->data < lst->next->next->data && lst->next->next)
			lst = rotate(stackb, 0);
		lst = stackb;
		if (lst->data < lst->next->data)
			stackb = swap(lst, 0); 
	}
	else if (lst->next->data < lst->next->next->data)
		checking_lastcase_rev(stackb, stacka);
	return (stackb);
}

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

t_dlist	**insert_test(t_dlist **head, t_dlist *node)
{
	t_dlist *temp;

	if (!head)
		head = &node;
	else if (node && head)
	{
		temp = *head;
		node->next = temp;
		temp->prev = node;
		head = &node;
	}
	return(head);
}

t_dlist	*pushing_tob(t_dlist *lsta, t_dlist *lstb, int size)
{
	int	i;
	t_dlist	*temp;

	i = 0;
	if (!lstb)
		temp = NULL;
	else
		temp = lstb;
	while (i < size / 2)
	{
		if (!temp)
			temp = ft_createnode(lsta->data);
		else
		{
			temp->prev = ft_createnode(lsta->data);
			temp->prev->next = temp;
			temp = temp->prev;
		}
		lsta = lsta->next;
		i++;
	}
	return (temp);
}

t_dlist	*pushing_toa(t_dlist *lsta, t_dlist *lstb)
{
	int		i;
	t_dlist	*temp;
	t_dlist	*stackb;

	i = 0;
	stackb = lstb;
	temp = NULL;
	while (i < ft_tdsize(stackb))
	{
		temp = ft_createnode(lstb->data);
		lsta->prev = temp;
		temp->next = lsta;
		lsta = temp;
		lstb = lstb->next;
		i++;
	}
	return (lsta);
	free_list(&temp);
}

t_dlist	*deletefroma(t_dlist *lsta, int size)
{
	int	i;
	t_dlist	*temp;
	t_dlist	*stacka;

	i = 0;
	temp = NULL;
	while (i < size / 2)
	{
		temp = lsta;
		lsta = lsta->next;
		temp->next = NULL;
		lsta->prev = NULL;
		free (temp);
		ft_printf("pb\n");
		i++;
	}
	stacka = lsta;
	return (stacka);
}

t_dlist	*deletefromb(t_dlist *lstb)
{
	t_dlist	*temp;

	temp = NULL;
	while (lstb->next)
	{
		temp = lstb;
		lstb = lstb->next;
		temp->next = NULL;
		lstb->prev = NULL;
		free(temp);
		ft_printf("pa\n");
	}
	ft_printf("pa\n");
	return (NULL);
}

int	check_max(t_dlist *lsta)
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
	else if ((a == 1 && b == 3) || (a == 3 && b == 1))
		return (3);
	else if ((a == 1 && b > 3) || (a > 3 && b == 1))
		return (4);
	else if ((a == 2 && b == 3) || (a == 3 && b == 2))
		return (5);
	else if ((a == 2) || (b == 2))
		return (6);
	return (7);
}

t_dlist	*checking_a(t_dlist *lsta)
{
	t_dlist	*stacka;
	int		a;

	stacka = lsta;
	a = check_max(lsta);
	if (a == 1 || a == 2)
	{
		if (a == 2)
			stacka = swap(lsta, 1);
		stacka = rotate(stacka, 1);
		stacka = rotate(stacka, 1);
	}
	else if (a == 4)
		stacka = rotate(stacka, 1);
	else if (a == 3)
	{
		stacka = r_rotate(stacka, 1);
		stacka = r_rotate(stacka, 1);
	}
	else if (a == 5)
	{
		stacka = r_rotate(stacka, 1);
		stacka = r_rotate(stacka, 1);
	}
	else if (a == 6)
	{
		stacka = swap(lsta, 1);
		stacka = rotate(stacka, 1);
	}
	return(stacka);
}

void	sort5numbers(t_dlist *stacka, t_dlist *stackb)
{
	t_dlist	*testb;
	t_dlist	*testa;
	int		b;
	int		a;

	stackb = NULL;
	testb = NULL;
	
	testa = stacka;
	
	stacka = checking_a(testa);
	testa = stacka;
	a = checking_ifordered(testa);
	if (!a)
		exit(EXIT_SUCCESS);
	
	stackb = pushing_tob(testa, testb, ft_tdsize(stacka));
	testb = stackb;
	stacka = deletefroma(testa, ft_tdsize(testa));
	testa = stacka;

	a = checking_ifordered(testa);
	b = checking_ifordered_b(testb);
	if (a != 0)
	{
		stacka = sort3numbers(testa, stackb);
		testa = stacka;
	}
	if (b != 0)
	{
		stackb = swap(testb, 2);
		testb = stackb;
	}
	if (testb->data > testa->data)
	{
		stackb = pushing_tob(testa, testb, ft_tdsize(stacka));
		testb = stackb;
		stacka = deletefroma(testa, ft_tdsize(stacka));
		testa = stacka;
		b = checking_ifordered_b(testb);
		testb = stackb;
		if (b != 0)
			stackb = sort3numbers_rev(testb, stacka);
		testa = stacka;
		testb = stackb;
	}
	stacka = pushing_toa(testa, testb);
	stackb = deletefromb(testb);
	//print_dblist(stacka);
	//print_dblist(stackb);
}

void	annalysing_stack(t_dlist *stacka)
{
	int		a;
	t_dlist	*stackb;
	t_dlist	*lst;

	stackb = NULL;
	lst = stacka;
	a = checking_ifordered(stacka);
	if (a == 0)
	{
		free_list(&stacka);
		exit(EXIT_SUCCESS);
	}
	if (ft_tdsize(stacka) < 3)
		stacka = swap(lst, 1);
	else if (ft_tdsize(stacka) < 4)
		sort3numbers(stacka, stackb);
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
	//print_dblist(stacka);
	annalysing_stack(stacka);
	free_list(&stacka);
	return (0);
}

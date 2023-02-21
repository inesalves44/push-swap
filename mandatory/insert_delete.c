/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:27:15 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/21 14:09:18 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*insert_node(t_dlist *head, t_dlist *node)
{
	t_dlist *final;
	t_dlist *temp;

	final = NULL;
	if (!head)
	{
		final = node;
		return (final);
	}
	else if (node && head)
	{
		temp = head;
		node->next = temp;
		temp->prev = node;
		head = node;
		final = head;
		return (final);
	}
	return (final);
}

t_dlist	*delete_node(t_dlist *head)
{
	t_dlist	*lst;
	t_dlist	*test;

	test = head;
	lst = NULL;
	if (ft_tdsize(head) > 1)
	{
		head = test->next;
		head->prev = NULL;
		test->next = NULL;
		lst = head;
		free(test);
	}
	else if (ft_tdsize(head) > 0)
	{
		head = NULL;
		lst = NULL;
		free(test);
	}
	return (lst);
}

t_dlist *stack_creation(char *args, t_dlist *head)
{
	t_dlist	*lst_temp;
	int		number;

	lst_temp = NULL;
	if (args[0] == '0' && ft_strlen(args) == 1)
		number = 0;
	else
	{
		number = ft_atoi(args);
		if (!number)
		{	
			ft_printf("Error\n");
			free_list(&head);
			exit (EXIT_FAILURE);
		}
	}
	lst_temp = ft_createnode(number);
	lst_temp->prev = head;
	head->next = lst_temp;
	return (lst_temp);
}

t_dlist	*firt_list(char **argv, int argc)
{
	t_dlist	*lst;
	int		number;
	int		i;

	i = 1;
	if (argv[1][0] == '0' && ft_strlen(argv[1]) == 1)
		number = 0;
	else
	{
		number = ft_atoi(argv[1]);
		if (!number)
		{	
			ft_printf("Error\n");
			exit (EXIT_FAILURE);
		}
	}
	lst = ft_createnode(number);
	i++;
	while (i < argc)
	{
		lst->next = stack_creation(argv[i], lst);
		lst = lst->next;
		i++;
	}
	return (lst);
}

int	checking_list(t_dlist *lst)
{
	t_dlist	*new;
	int		a;
	int		number;

	a = 0;
	new = lst;
	while (a < ft_tdsize(lst))
	{
		number = lst->data;
		lst = lst->next;
		while (lst)
		{
			if (lst->data == number)
			{
				a = 80000;
				return (a);
			}
			lst = lst->next;
		}
		lst = new;
		lst = lst->next;
		a++;
	}
	return (a);
}

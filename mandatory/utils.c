/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:19:56 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/02 11:29:37 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*ft_createnode(int data)
{
	t_dlist	*node;

	node = malloc(sizeof(t_dlist));
	if (node)
	{
		node->data = data;
		node->next = NULL;
		node->prev = NULL;
	}
	return (node);
}

int	ft_tdsize(t_dlist *head)
{
	int		i;
	t_dlist	*lst;

	i = 0;
	if (!head)
		return (0);
	lst = head;
	if (lst->prev)
		while (lst->prev)
			lst = lst->prev;
	if (!lst->next)
		return (1);
	while (lst)
	{
		i++;
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	while (lst->prev)
		lst = lst->prev;
	return (i);
}

void	free_list(t_dlist **head)
{
	t_dlist	*lst;

	lst = *head;
	if (head)
	{
		while (lst)
		{
			lst->data = 0;
			if (lst->next)
			{
				lst = lst->next;
				free(lst->prev);
			}
			else
			{
				free(lst);
				break ;
			}
		}
	}
}

t_dlist	*reorder_stacks(t_dlist *stacka)
{
	if (stacka)
	{
		while (stacka->prev)
			stacka = stacka->prev;
	}
	return (stacka);
}

void	print_dblist(t_dlist *lst)
{
	if (lst)
	{		
		ft_printf("-------front list-------\n");
		while (lst)
		{
			ft_printf("%d\n", lst->data);
			if (lst->next == NULL)
				break ;
			lst = lst->next;
		}
		ft_printf("------- back list-------\n");
		while (lst)
		{
			ft_printf("%d\n", lst->data);
			lst = lst->prev;
		}
	}
	else
		ft_printf("NO LIST\n");
}

void	print_dblist2(t_dlist *lst1, t_dlist *lst2)
{
	if (lst1 && lst2)
	{		
		ft_printf("A \t B\n");
		while (lst1 || lst2)
		{
			if (lst1 && lst2)
				ft_printf("%d \t %d\n", lst1->data, lst2->data);
			else if (lst1 && !lst2)
				ft_printf("%d \t\n", lst1->data);
			else if (!lst1 && lst2)
				ft_printf("  \t %d\n", lst2->data);
			if (lst2->next && lst1->next)
			{
				lst2 = lst2->next;
				lst1 = lst1->next;
			}
			else if (lst2->next && !lst1->next)
				lst2 = lst2->next;
			else if (lst1->next && !lst2->next)
				lst1 = lst1->next;
			else if (!lst2->next && !lst1->next)
				break ;
		}
	}
}
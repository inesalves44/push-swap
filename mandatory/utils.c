/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:19:56 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/21 16:48:11 by idias-al         ###   ########.fr       */
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
	t_dlist *lst;

	i = 0;
	lst = head;
	if (lst->prev)
	{
		while (lst)
		{
			if (!lst->prev)
				break ;
			lst = lst->prev;
		}
	}
	if (!head)
		return (0);
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

void	print_dblist(t_dlist *lst)
{
	if (lst)
	{		
		ft_printf("-------front list-------\n");
		while (lst)
		{
			ft_printf("%d\n", lst->data);
			if (lst->next == NULL)
				break;		
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

void	free_list(t_dlist **head)
{
	t_dlist	*lst;

	lst = *head;
	if (head)
	{
		while(lst)
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
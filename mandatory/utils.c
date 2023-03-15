/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:19:56 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/15 12:57:51 by idias-al         ###   ########.fr       */
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

t_dlist	**reorder_stacks(t_dlist **stacka)
{
	if (stacka)
	{
		while ((*stacka)->prev)
			*stacka = (*stacka)->prev;
	}
	return (stacka);
}

t_utils	creting_struck(t_dlist *stacka)
{
	t_utils	utils;

	utils.size = ft_tdsize(stacka);
	if (ft_tdsize(stacka) % 2 == 0)
		utils.half = ft_tdsize(stacka) / 2;
	else
		utils.half = ft_tdsize(stacka) / 2 + 1;
	if (ft_tdsize(stacka) % 4 == 0)
		utils.quarter = ft_tdsize(stacka) / 4;
	else
		utils.quarter = ft_tdsize(stacka) / 4 + 1;
	utils.quarter_first = 0;
	utils.max = get_max(stacka);
	utils.min = get_min(stacka);
	utils.posmin = find_number(stacka, utils.min);
	utils.posmax = find_number(stacka, utils.max);
	utils.high = 0;
	utils.pos = 0;
	utils.min_b = 0;
	utils.max_b = 0;
	utils.movements_a = 0;
	utils.movements_b = 0;
	utils.movements_t = 0;
	utils.movements_t_final = 0;
	utils.value_b = 0;
	utils.value_a = 0;
	utils.rotate_b = 'y';
	return (utils);
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
		/*ft_printf("------- back list-------\n");
		while (lst)
		{
			ft_printf("%d\n", lst->data);
			lst = lst->prev;
		}*/
	}
	else
		ft_printf("NO LIST\n");
}

void	print_dblist2(t_dlist *lst1, t_dlist *lst2)
{
	if (lst1 || lst2)
	{
		ft_printf("\n\n");
		ft_printf("A \t B\n");
		while (lst1 && lst2)
		{
			ft_printf("%d \t %d\n", lst1->data, lst2->data);
			lst2 = lst2->next;
			lst1 = lst1->next;
		}
		if (lst1)
		{
			while (lst1)
			{
				ft_printf("%d \t\n", lst1->data);
				if (!lst1->next)
					break ;
				lst1 = lst1->next;
			}
		}
		if (lst2)
		{
			while (lst2)
			{
				ft_printf("  \t %d\n", lst2->data);
				if (!lst2->next)
					break ;
				lst2 = lst2->next;
			}
		}
		ft_printf("\n\n");
	}
}
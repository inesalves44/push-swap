/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:04:33 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/19 12:00:13 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

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

/* Second Print function!!*/
/*void	print_dblist2(t_dlist *lst1, t_dlist *lst2)
{
	if (lst1 || lst2)
	{
		ft_printf("\nA \t B\n");
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
	}
}*/
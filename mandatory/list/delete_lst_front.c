/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_lst_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:45:12 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/20 11:12:55 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_dlist	*delete_from_front(t_dlist *lsta)
{
	t_dlist	*temp;

	temp = lsta;
	if (!lsta->next)
		lsta = NULL;
	else
	{
		lsta = lsta->next;
		lsta->prev = NULL; 
	}
	temp->next = NULL;
	free(temp);
	if (!lsta)
		return (NULL);
	while (lsta->prev)
		lsta = lsta->prev;
	return (lsta);
}

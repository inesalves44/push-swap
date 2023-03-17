/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_lst_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:45:12 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/16 16:22:45 by idias-al         ###   ########.fr       */
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
		lsta = lsta->next;
	temp->next = NULL;
	lsta->prev = NULL;
	free(temp);
	while (lsta->prev)
		lsta = lsta->prev;
	return (lsta);
}

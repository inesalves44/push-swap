/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:28:12 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/24 00:04:37 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_dlist	*pushing_toa(t_dlist *lsta, t_dlist *lstb)
{
	int		i;
	t_dlist	*temp;
	t_dlist	*stackb;

	i = 0;
	if (!lstb)
		return(lsta);
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
	while (lsta->prev)
		lsta = lsta->prev;
	return (lsta);
	free_list(&temp);
}

t_dlist	*pushing_tob(t_dlist *lsta, t_dlist *lstb, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		if (!lstb)
			lstb = ft_createnode(lsta->data);
		else
		{
			lstb->prev = ft_createnode(lsta->data);
			lstb->prev->next = lstb;
			lstb = lstb->prev;
		}
		lsta = lsta->next;
		i++;
	}
	while (lsta->prev)
		lsta = lsta->prev;
	while (lstb->prev)
		lstb = lstb->prev;
	return (lstb);
}

t_dlist	*deletefroma(t_dlist *lsta, int size)
{
	int	i;
	t_dlist	*temp;

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
	lsta = reorder_stacks(lsta);
	return (lsta);
}

t_dlist	*deletefromb(t_dlist *lstb)
{
	t_dlist	*temp;

	while (lstb)
	{
		if (lstb->next)
		{
			temp = lstb;
			lstb = lstb->next;
			temp->next = NULL;
			lstb->prev = NULL;
			free(temp);	
		}
		else
		{
			free(lstb);
			break ;
		}
		ft_printf("pa\n");
	}
	ft_printf("pa\n");
	return (NULL);
}
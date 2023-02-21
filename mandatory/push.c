/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:28:12 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/20 10:54:56 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*push(t_dlist *input, t_dlist *output, int a)
{
	t_dlist	*node;
	t_dlist	*lst;
	t_dlist	*final;
	int		temp;

	if (input)
	{
		lst = input;
		temp = lst->data;
		node = ft_createnode(temp);
		input = delete_node(lst);
		final = insert_node(output, node);
		if (a == 1)
			ft_printf("pa\n");
		else
			ft_printf("pb\n");
	}
	return (final);
}
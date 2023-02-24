/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:56:25 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/24 13:27:12 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

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
	stacka = reorder_stacks(stacka);
	return (a);
}


int	checking_ifordered_b(t_dlist *stackb)
{
	int		a;

	a = 0;
	while (stackb->next)
		stackb = stackb->next;
	while (stackb->prev)
	{
		if (stackb->data > stackb->prev->data)
			a++;
		stackb = stackb->prev;
	}
	stackb = reorder_stacks(stackb);
	return (a);
}

void	annalysing_stack(t_dlist *stacka)
{
	t_dlist	*stackb;
	t_dlist	*lst;

	stackb = NULL;
	lst = stacka;
	if (checking_ifordered(stacka) == 0)
	{
		free_list(&stacka);
		exit(EXIT_SUCCESS);
	}
	if (ft_tdsize(stacka) < 3)
		stacka = swap(lst, 1);
	else if (ft_tdsize(stacka) < 4)
		sort3numbers(stacka, &stackb);
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
	lst = first_list(argv, argc);
	while (lst->prev)
		lst = lst->prev;
	stacka = create_stack(lst);
	free_list(&lst);
	if (!stacka)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	annalysing_stack(stacka);
	return (0);
}

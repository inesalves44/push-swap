/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:56:25 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/19 13:27:01 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

t_dlist	*annalysing_stack(t_dlist *stacka, t_dlist **stackb)
{
	t_utils	utils;

	utils = creting_struck(stacka);
	if (checking_ifordered(stacka, 1) == 1)
	{
		free_list(&stacka);
		exit(EXIT_SUCCESS);
	}
	if (ft_tdsize(stacka) < 3)
		stacka = swap(stacka, &utils);
	else if (ft_tdsize(stacka) < 4)
		stacka = sort3numbers(stacka, &utils);
	else if (ft_tdsize(stacka) < 6)
		stacka = sort5numbers(stacka, stackb, &utils);
	else if (ft_tdsize(stacka) <= 500)
		stacka = bigalgorithm(stacka, stackb, &utils);
	return (stacka);
}

int	main(int argc, char *argv[])
{
	t_dlist	*lst;
	t_dlist	*stacka;
	t_dlist	*stackb;

	if (argc < 2)
		return (0);
	checking_digits(argv);
	lst = first_list(argv, argc);
	stacka = create_stack(lst);
	free_list(&lst);
	if (!stacka)
		error_func(NULL);
	stackb = NULL;
	stacka = annalysing_stack(stacka, &stackb);
	free_list(&stacka);
	return (0);
}

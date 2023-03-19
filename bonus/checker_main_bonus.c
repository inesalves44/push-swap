/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:10:09 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/19 13:23:58 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_dlist	*lst;
	t_dlist	*stacka;
	//t_dlist	*stackb;

	if (argc < 2)
		return (0);
	checking_digits(argv);
	lst = first_list(argv, argc);
	stacka = create_stack(lst);
	free_list(&lst);
	if (!stacka)
		error_func(NULL);
	//stackb = NULL;
	//stacka = annalysing_stack(stacka, &stackb);
	free_list(&stacka);
	return (0);
}
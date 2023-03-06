/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:05:55 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/06 11:31:38 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/push_swap.h"

int	main(void)
{
	char *str;
	char *str1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	int a = 0;
	int b = 0;
	int fd = open("txt", O_RDONLY);
	str1 = get_next_line(fd);
	j++;
	while (1)
	{	
			str = get_next_line(fd);
			if (!str)
				break ;
			if (!ft_strncmp(str, "ra", 2))
				if (!ft_strncmp(str1, "rb", 2))
					i++;
			else if (!ft_strncmp(str, "rb", 2))
				if (!ft_strncmp(str1, "ra", 2))
					i++;
			else if (!ft_strncmp(str, "rra", 2))
				if (!ft_strncmp(str1, "rrb", 2))
					a++;
			else if (!ft_strncmp(str, "rrb", 2))
				if (!ft_strncmp(str1, "rra", 2))
					a++;
			else if (!ft_strncmp(str, "sa", 2))
				if (!ft_strncmp(str1, "sb", 2))
					b++;
			else if (!ft_strncmp(str, "sb", 2))
				if (!ft_strncmp(str1, "sa", 2))
					b++;
			str1 = str;
			j++;
	}
	printf("ra and rb: %d\n", i);
	printf("rra and rrb: %d\n", a);
	printf("sa and sb: %d\n", b);
}

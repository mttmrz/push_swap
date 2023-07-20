/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <mmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:35:21 by mmarzano          #+#    #+#             */
/*   Updated: 2023/07/20 22:12:14 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_array	array;
	int		i;

	i = -1;
	if (ac > 2)
	{
		while (++i < ac)
			array.a_tot = i;
		array.tot_a = ac;
		check_ac(&array, ac, av);
		initi(&array, i);
		i = -1;
		while (++i < array.a_tot)
		{
			array.dump[i] = ft_atoi(av[i + 1]);
			array.astack[i] = ft_atoi(av[i + 1]);
		}
		check_rep(&array);
		lis(i, &array);
		free_all(&array);
	}
}

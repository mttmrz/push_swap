/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minlis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <mmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:47:21 by mmarzano          #+#    #+#             */
/*   Updated: 2023/07/20 22:12:28 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(char **argv, int argc)
{
	int	i;

	i = 0;
	while (++i < argc - 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (0);
	}
	return (1);
}

void	no_space(t_array *array, int i, int shortest, int x)
{
	while (++i < array->a_tot)
	{
		if (array->astack[i] > shortest)
		{
			shortest = array->astack[i];
			x++;
		}
	}
}

int	minlis(t_array *array, int a)
{
	int	i;
	int	c;
	int	x;
	int	k;
	int	shortest;

	x = 0;
	k = 0;
	c = -1;
	while (++c < array->a_tot)
	{
		i = c;
		x = 1;
		shortest = array->astack[c];
		no_space(array, i, shortest, x);
		if (x > a)
		{
			array->last_lis = shortest;
			a = x;
			x = 1;
			k = c;
		}
	}
	return (k);
}

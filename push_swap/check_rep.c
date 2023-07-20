/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <mmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:57:11 by mmarzano          #+#    #+#             */
/*   Updated: 2023/07/20 22:11:11 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_sorted(t_array *array)
{
	int	i;
	int	x;

	i = 0;
	while (i < array->a_tot)
	{
		x = 0;
		while (x < i)
		{
			if (array->astack[x] > array->astack[i])
				return ;
			x++;
		}
		i++;
	}
	exit (0);
}

void	check_rep(t_array *array)
{
	int	i;
	int	current;

	current = 0;
	while (current < array->a_tot - 1)
	{
		i = current + 1;
		while (array->dump[current] != array->dump[i] && i < array->a_tot - 1)
			i++;
		if (array->dump[current] == array->dump[i])
		{
			array->ck = 1;
			free_all(array);
			exit (write(2, "Error\n", 6));
		}
		current++;
	}
	is_sorted(array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <mmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:17:21 by mmarzano          #+#    #+#             */
/*   Updated: 2023/07/20 22:11:56 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	findm(t_array *array, int i, int *c, int *x)
{
	int	a;
	int	b;

	a = array->ab[i];
	b = array->b[i];
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (i == 0)
		*c = a + b;
	if (a + b < *c)
	{
		*c = a + b;
		*x = i;
	}
}

void	bu(int *a, int *b)
{
	if (*a < 0 && *b < 0)
	{
		*a *= -1;
		*b *= -1;
	}
}

void	pu(int a, int b, int **c)
{
	if (a < b)
		**c = b;
	else
		**c = a;
}

void	findus(t_array *array, int i, int *x, int *c)
{
	int	a;
	int	b;

	a = array->ab[i];
	b = array->b[i];
	bu(&a, &b);
	if (i == 0)
		pu(a, b, &c);
	if (a > b)
	{
		if (a < *c)
		{
			*c = a;
			*x = i;
		}
	}
	else
	{
		if (b < *c)
		{
			*c = b;
			*x = i;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <mmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:57:21 by mmarzano          #+#    #+#             */
/*   Updated: 2023/07/20 22:10:08 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_array *array)
{
	free(array->astack);
	free(array->dump);
	if (array->ck == 0)
	{
		free(array->bstack);
		free(array->bsub);
	}
	free(array->bdump);
	free(array->adump);
}

void	ab_pos(t_array *array, int a, int b)
{
	if (a >= b)
	{
		while (a >= b && b > 0)
		{
			rr(array);
			a--;
			b--;
		}
	}
	else if (b > a)
	{
		while (b >= a && a > 0)
		{
			rr(array);
			a--;
			b--;
		}
	}
	while (--a >= 0)
		ra(array);
	while (--b >= 0)
		rb(array);
	push_a(array);
}

void	ab_neg(t_array *array, int a, int b)
{
	if (a >= b)
	{
		while (a >= b && a < 0)
		{
			rrr(array);
			a++;
			b++;
		}
	}
	else if (b > a)
	{
		while (b >= a && b < 0)
		{
			rrr(array);
			a++;
			b++;
		}
	}
	while (++a <= 0)
		rraa(array);
	while (++b <= 0)
		rrb(array);
	push_a(array);
}

void	apos_bneg(t_array *array, int a, int b)
{
	while (--a >= 0)
		ra(array);
	while (++b <= 0)
		rrb(array);
	push_a(array);
}

void	aneg_bpos(t_array *array, int a, int b)
{
	while (++a <= 0)
		rraa(array);
	while (--b >= 0)
		rb(array);
	push_a(array);
}

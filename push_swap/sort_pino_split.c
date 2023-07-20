/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pino_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <mmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:57:21 by mmarzano          #+#    #+#             */
/*   Updated: 2023/07/20 22:10:14 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	pino_one(t_array *array, int i)
{
	while (i < 5 && array->dump[i] != max_five(array))
		i++;
	if (i < 2)
	{
		while (i >= 0)
		{
			rafive(array);
			i--;
		}
	}
	else
	{
		while (i < 3)
		{
			rra(array);
			i++;
		}
	}
	push_aa(array);
}

void	pino_two(t_array *array, int i, int shortest)
{
	while (i < 4)
	{
		if (array->dump[i] < shortest)
			shortest = array->dump[i];
		i++;
	}
	i = 0;
	while (array->dump[i] != shortest)
		i++;
	if (i < 2)
	{
		while (i > 0)
			rafive(array);
		i--;
	}
	else
	{
		while (i < 4)
		{
			rra(array);
			i++;
		}
	}
	push_aa(array);
}

void	pino_three(t_array *array, int i)
{
	while (array->dump[i] < array->dump[i + 1]
		&& array->bdump[0] > array->dump[i])
		i++;
	if (i < 2)
	{
		while (i > 0)
		{
			rafive(array);
			i--;
		}
	}
	else
	{
		while (i < 4)
		{
			rra(array);
			i++;
		}
	}
	push_aa(array);
}

void	pino_four(t_array *array, int i)
{
	while (array->bdump[0] > array->dump[i])
		i++;
	if (i < 2)
	{
		while (i > 0)
		{
			rafive(array);
			i--;
		}
	}
	else
	{
		while (i < 4)
		{
			rra(array);
			i++;
		}
	}
	push_aa(array);
}

void	pino_five(t_array *array, int i)
{
	while (array->bdump[0] < array->dump[i])
		i++;
	if (i < 2)
	{
		while (i > 0)
		{
			rafive(array);
			i--;
		}
	}
	else
	{
		while (i < 3)
		{
			rra(array);
			i++;
		}
	}
	push_aa(array);
}

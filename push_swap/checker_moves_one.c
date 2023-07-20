/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <mmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:51:21 by mmarzano          #+#    #+#             */
/*   Updated: 2023/07/20 22:11:16 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	rac(t_checker *checker)
{
	int	last;
	int	*tmp;
	int	i;

	last = checker->ap_tot - 1;
	i = -1;
	tmp = malloc(sizeof(int) * 1);
	*tmp = checker->apile[0];
	while (++i < last)
		checker->apile[i] = checker->apile[i + 1];
	checker->apile[last] = *tmp;
	free(tmp);
}

void	rrac(t_checker *checker)
{
	int	last;
	int	*tmp;

	last = checker->ap_tot - 1;
	tmp = malloc(sizeof(int) * 1);
	*tmp = checker->apile[last];
	while (last > 0)
	{
		checker->apile[last] = checker->apile[last - 1];
		last--;
	}
	checker->apile[0] = *tmp;
	free(tmp);
}

void	rbc(t_checker *checker)
{
	int	last;
	int	*tmp;
	int	i;

	if (checker->bp_tot == 0)
		return ;
	last = checker->bp_tot;
	i = -1;
	tmp = malloc(sizeof(int) * 1);
	*tmp = checker->bpile[0];
	while (++i < last)
		checker->bpile[i] = checker->bpile[i + 1];
	checker->bpile[last - 1] = *tmp;
	free(tmp);
}

void	rrbc(t_checker *checker)
{
	int	last;
	int	*tmp;

	if (checker->bp_tot == 0)
		return ;
	last = checker->bp_tot - 1;
	tmp = malloc(sizeof(int) * 1);
	*tmp = checker->bpile[last];
	while (last > 0)
	{
		checker->bpile[last] = checker->bpile[last - 1];
		last--;
	}
	checker->bpile[0] = *tmp;
	free(tmp);
}

void	rrrc(t_checker *checker)
{
	rrac(checker);
	rrbc(checker);
}

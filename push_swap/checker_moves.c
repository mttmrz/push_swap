/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzano <mmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:27:21 by mmarzano          #+#    #+#             */
/*   Updated: 2023/07/20 22:11:41 by mmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	swap_bc(t_checker *checker)
{
	int	*tmp;

	if (!checker->bpile)
		return ;
	tmp = malloc(sizeof(int) * 1);
	*tmp = checker->bpile[1];
	checker->bpile[1] = checker->bpile[0];
	checker->bpile[0] = *tmp;
	free(tmp);
}

void	ssc(t_checker *checker)
{
	swap_ac(checker);
	swap_bc(checker);
}

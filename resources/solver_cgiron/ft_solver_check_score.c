/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_check_score.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:37:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/06 10:37:40 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_update_solution(t_filler *mf, int score[2] ,int i, int j)
{
	mf->best_score[0] = score[0];
	mf->answerx = i;
	mf->answery = j;
}

int		ft_only_one_adversary(t_filler *mf, int i, int j)
{
	int cov_piece;
	int	score[2];
	int ii;
	int jj;

	ft_bzero(score,sizeof(score));
	cov_piece = 0;
	jj = -1;
	while ((ii = -1) && ++jj < mf->pszy)
	{
		while (++ii < mf->pszx)
		{
			if (mf->piece[jj][ii] != '*')
				continue;
			cov_piece += mf->board[j + jj][i + ii] == mf->player ? 1 : 0;
			if (mf->board[j + jj][i + ii] == mf->adv || cov_piece > 1)
				return (0);
			score[0] += mf->board[j + jj][i + ii];
			score[1] += ft_abs( 2 * (i + ii) - mf->bszx) + 
						ft_abs( 2 * (j + jj) - mf->bszy);
		}
	}
	if (cov_piece != 1 || (score[0] < mf->best_score[0] && mf->best_score[0] && mf->alone))
		return (0);
	ft_update_solution(mf, score, i, j);
	return (1);
}

void	ft_solver_check_score(t_filler *mf, int i, int j)
{
	if (i + mf->pszx > mf->bszx || j + mf->pszy > mf->bszy)
		return;
	if (!ft_only_one_adversary(mf, i, j))
		return;
	mf->board[j][i] = mf->board[j][i] < 0 ? 4 : mf->board[j][i];
}                  

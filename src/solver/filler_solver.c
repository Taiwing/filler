/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:51:33 by yforeau           #+#    #+#             */
/*   Updated: 2019/09/09 12:01:29 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "t_filldata.h"
#include "heat_map.h"

static void	skim_board(t_filldata *mst, int start_i, int start_j,
		void (*f)(t_filldata *mst, int i, int j))
{
	int	i;
	int	j;

	j = start_j;
	while (++j < mst->board_height)
	{
		i = start_i;
		while (++i < mst->board_width)
			f(mst, i, j);
	}
}

static int	test_pos(t_filldata *mst, int i, int j)
{
	int	x;
	int	y;
	int	cur_pos;
	int	connect;

	connect = 0;
	cur_pos = 0;
	y = -1;
	while (++y < mst->token_height && cur_pos != 1 && connect < 2)
	{
		x = -1;
		while (++x < mst->token_width && cur_pos != 1 && connect < 2)
			if (mst->token[y][x] == '*')
			{
				if (j + y < 0 || i + x < 0
					|| j + y >= mst->board_height || i + x >= mst->board_width
					|| mst->board[j + y][i + x] == mst->adv)
					cur_pos = 1;
				else if (mst->board[j + y][i + x] == mst->player)
					++connect;
				else
					cur_pos += mst->board[j + y][i + x];
			}
	}
	return (cur_pos < 0 && connect == 1 ? cur_pos : INT_MIN);
}

static void	put_token(t_filldata *mst, int i, int j)
{
	static int	last_pos = INT_MIN;
	int			cur_pos;

	cur_pos = INT_MIN;
	if (i == 1 - mst->token_width && j == 1 - mst->token_height)
		last_pos = INT_MIN;
	cur_pos = test_pos(mst, i, j);
	if (cur_pos > last_pos)
	{
		last_pos = cur_pos;
		mst->answerx = i;
		mst->answery = j;
	}
}

void		filler_solver(t_filldata *mst)
{
	mst->adv = mst->player == P_O ? P_X : P_O;
	skim_board(mst, -1, -1, &init_heatmap);
	skim_board(mst, -1, -1, &fill_heatmap);
	skim_board(mst, -mst->token_width, -mst->token_height, &put_token);
}

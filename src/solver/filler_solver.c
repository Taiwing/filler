/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:51:33 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/29 04:25:03 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "t_filldata.h"
#include "heat_map.h"

static void	skim_board(t_filldata *mst,
		void (*f)(t_filldata *mst, int i, int j))
{
	int	i;
	int	j;

	j = -1;
	while (++j < mst->board_height)
	{
		i = -1;
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
		{
			if (mst->token[y][x] == '*')
			{
				if (mst->board[j + y][i + x] == mst->adv)
					cur_pos = 1;
				else if (mst->board[j + y][i + x] == mst->player)
					++connect;
				else
					cur_pos += mst->board[j + y][i + x];
			}
		}
	}
	return (cur_pos < 0 && connect == 1 ? cur_pos : INT_MIN);
}

static void	put_token(t_filldata *mst, int i, int j)
{
	static int	last_pos = INT_MIN;
	int			cur_pos;

	cur_pos = INT_MIN;
	if (!i && !j)
		last_pos = INT_MIN;
	if (i + mst->token_width <= mst->board_width
		&& j + mst->token_height <= mst->board_height)
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
	skim_board(mst, &init_heatmap);
	skim_board(mst, &fill_heatmap);
	skim_board(mst, &put_token);
}

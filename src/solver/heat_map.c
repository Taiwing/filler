/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:40:01 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/24 01:34:51 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_filldata.h"

static int	ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

static int	update_value(int *place, int value)
{
	if (value > *place)
	{
		*place = value;
		return (1);
	}
	return (0);
}

static void	update_heatmap(t_filldata *mst, int i, int j, int dist)
{
	int	x;
	int	y;
	int	max_x;
	int	max_y;
	int	change;

	change = 0;
	max_x = i + dist < mst->board_width - 1 ? i + dist : mst->board_width - 1;
	max_y = j + dist < mst->board_height - 1 ? j + dist : mst->board_height - 1;
	y = j - dist > 0 ? j - dist : 0;
	while (y <= max_y)
	{
		x = i - dist > 0 ? i - dist : 0;
		while (x <= max_x)
		{
			if (update_value(&mst->board[y][x],
				-(ft_abs(i - x) + ft_abs(j - y) + dist)))
				change = 1;
			x = x == max_x || y == j - dist || y == 0 || y == max_y
				? x + 1 : max_x;
		}
		++y;
	}
	if (change)
		update_heatmap(mst, i, j, dist + 1);
}

void		fill_heatmap(t_filldata *mst, int i, int j)
{
	if (mst->board[j][i] == mst->adv)
		update_heatmap(mst, i, j, 1);
}

void		init_heatmap(t_filldata *mst, int i, int j)
{
	if (mst->board[j][i] == P_EMPTY)
		mst->board[j][i] = -(mst->board_height + mst->board_width);
}

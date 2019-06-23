/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:40:01 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/23 21:23:11 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_filldata.h"

static void	update_heatmap(t_filldata *mst, int i, int j, int dist)
{
	(void)mst;
	(void)i;
	(void)j;
	(void)dist;
}

void		fill_heatmap(t_filldata *mst, int i, int j)
{
	if (mst->board[j][i] == mst->adv)
		update_heatmap(mst, i, j, 1); //update_heatmap
}

void		init_heatmap(t_filldata *mst, int i, int j)
{
	if (mst->board[j][i] == P_EMPTY)
		mst->board[j][i] = -(mst->board_height + mst->board_width);
}

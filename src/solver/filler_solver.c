/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:51:33 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/14 14:45:10 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		filler_solver(t_filldata *mst)
{
	mst->adv = mst->player == P_O ? P_X : P_O;
	skim_board(mst, &init_heatmap);	//init_heatmap
	skim_board(mst, &fill_heatmap);	//fill_heatmap
	//put_token
}

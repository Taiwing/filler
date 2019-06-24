/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:51:33 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/24 02:31:26 by yforeau          ###   ########.fr       */
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

#	include "libft.h"
static void	print_heatmap(t_filldata *mst)
{
	int	i;
	int	j;
	int red;
	int	step;

	step = 10;
	j = -1;
	while (++j < mst->board_height)
	{
		i = -1;
		while (++i < mst->board_width)
		{
			if (mst->board[j][i] == mst->adv)
				ft_printf("\033[38;2;255;0;0;m%c\033[0m",
						mst->adv == P_O ? 'O' : 'X');
			else if (mst->board[j][i] == mst->player)
			{
				ft_printf("\033[38;2;50;200;0;m%c\033[0m",
						mst->player == P_O ? 'O' : 'X');
			}
			else
			{
				red = 255 - (mst->board[j][i] * -step);
//				red = -(mst->board[j][i] * step);
				ft_printf("\033[48;2;%d;0;0;m \033[0m", red);
			}
		}
		ft_putchar('\n');
	}
}

void		filler_solver(t_filldata *mst)
{
	mst->adv = mst->player == P_O ? P_X : P_O;
	skim_board(mst, &init_heatmap);
	skim_board(mst, &fill_heatmap);
	print_heatmap(mst); //TEMP
	//put_token
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:41:15 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/14 13:54:17 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_arrays.h"
#include "filler_parser.h"
#include "filler_solver.h"
#include "libft.h"

void	write_mst(t_filldata *mst)
{
	int	fd;

	fd = 2;
	ft_dprintf(fd, "board_width=%d", mst->board_width);
	ft_dprintf(fd, "\nboard_height=%d", mst->board_height);
	ft_dprintf(fd, "\ntoken_width=%d", mst->token_width);
	ft_dprintf(fd, "\ntoken_height=%d", mst->token_height);
	ft_dprintf(fd, "\nanswerx=%d", mst->answerx);
	ft_dprintf(fd, "\nanswery=%d", mst->answery);
	ft_dprintf(fd, "\nplayer=%s", mst->player == P_O ? "P_O" : "P_X");
	ft_dprintf(fd, "\nadv=%s", mst->adv == P_O ? "P_O" : "P_X");
	ft_dprintf(fd, "\nround=%d", mst->round);
	ft_dprintf(fd, "\nalone=%d\n", mst->alone);
}

int	main(void)
{
	t_filldata	master;
	t_filldata	*mst;

	mst = &master;
	ft_bzero((void *)mst, sizeof(t_filldata));
	while (!filler_parser(mst))
	{
	//	write_mst(mst);	//debug
		mst->answerx = 0;
		mst->answery = 0;
		filler_solver(mst);
		ft_printf("%d %d\n", mst->answerx, mst->answery);
		if (mst->board)
			free_double_array((void ***)&mst->board);
		if (mst->token)
			free_double_array((void ***)&mst->token);
		++mst->round;
	}
	return (0);
}

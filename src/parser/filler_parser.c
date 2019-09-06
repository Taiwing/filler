/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:05:43 by yforeau           #+#    #+#             */
/*   Updated: 2019/09/06 10:24:07 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_arrays.h"
#include "filler_parser.h"
#include "libft.h"

static int	exit_parser(t_filldata *mst)
{
	if (mst->board)
		free_double_array((void ***)&mst->board);
	if (mst->token)
		free_double_array((void ***)&mst->token);
	if (!mst->round)
		ft_putstr("0 0\n");
	return (1);
}

int			filler_parser(t_filldata *mst)
{
	if (!mst->player && get_player(mst))
		return (exit_parser(mst));
	if (get_board_dims(mst))
		return (exit_parser(mst));
	if (get_board(mst))
		return (exit_parser(mst));
	if (get_token_dims(mst))
		return (exit_parser(mst));
	if (get_token(mst))
		return (exit_parser(mst));
	return (0);
}

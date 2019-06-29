/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:41:15 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/29 04:24:17 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_arrays.h"
#include "filler_parser.h"
#include "filler_solver.h"
#include "libft.h"

int	main(void)
{
	t_filldata	master;
	t_filldata	*mst;

	mst = &master;
	ft_bzero((void *)mst, sizeof(t_filldata));
	while (!filler_parser(mst))
	{
		mst->answerx = 0;
		mst->answery = 0;
		filler_solver(mst);
		ft_printf("%d %d\n", mst->answery, mst->answerx);
		if (mst->board)
			free_double_array((void ***)&mst->board);
		if (mst->token)
			free_double_array((void ***)&mst->token);
		++mst->round;
	}
	return (0);
}

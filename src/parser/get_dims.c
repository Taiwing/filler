/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dims.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:17:58 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/24 01:54:26 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_filldata.h"
#include "libft.h"

static void	get_dims(char *dims, int *x, int *y)
{
	*y = ft_atoi(dims);
	while (*dims && *dims > 47 && *dims < 58)
		++dims;
	*x = ft_atoi(dims);
}

int			get_board_dims(t_filldata *mst)
{
	char	*line;
	int		r;

	line = NULL;
	if ((r = get_next_line(0, &line)) > 0
		&& !ft_strncmp(line, "Plateau ", 8))
		get_dims(line + 8, &mst->board_width, &mst->board_height);
	if (r > -1)
		free(line);
	return (r < 1 || !mst->board_width || !mst->board_height);
}

int			get_token_dims(t_filldata *mst)
{
	char	*line;
	int		c;

	c = 0;
	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (1);
	if (ft_strncmp(line, "Piece ", 6))
	{
		free(line);
		return (1);
	}
	get_dims(line + 6, &mst->token_width, &mst->token_height);
	free(line);
	return (!mst->token_width || !mst->token_height);
}

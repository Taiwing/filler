/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arrays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:17:49 by yforeau           #+#    #+#             */
/*   Updated: 2019/09/06 10:39:50 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_arrays.h"
#include "t_filldata.h"
#include "libft.h"

static int	fill_board(const char *line, int *board, int len)
{
	int	j;

	j = 0;
	while (line[j] && j < len)
	{
		board[j] = P_OBS;
		if (line[j] == 'o' || line[j] == 'O')
			board[j] = P_O;
		else if (line[j] == 'x' || line[j] == 'X')
			board[j] = P_X;
		else if (line[j] == '.')
			board[j] = P_EMPTY;
		++j;
	}
	if (line[j] || j < len)
		return (1);
	return (0);
}

int			get_board(t_filldata *mst)
{
	int		i;
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (1);
	free(line);
	if (!(mst->board = (int **)alloc_double_array(mst->board_width,
			mst->board_height, sizeof(int))))
		return (1);
	i = 0;
	while (i < mst->board_height && get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) < 4
			|| fill_board(line + 4, mst->board[i++], mst->board_width))
		{
			free(line);
			return (1);
		}
		free(line);
	}
	return (i != mst->board_height);
}

static int	fill_token(const char *line, char *token, int len)
{
	int	j;

	j = 0;
	while (line[j] && j < len)
	{
		if (line[j] == '.' || line[j] == '*')
			token[j] = line[j];
		else
			return (1);
		++j;
	}
	return (line[j] || j < len);
}

int			get_token(t_filldata *mst)
{
	int		i;
	char	*line;

	line = NULL;
	if (!(mst->token = (char **)alloc_double_array(mst->token_width,
			mst->token_height, sizeof(char))))
		return (1);
	i = 0;
	while (i < mst->token_height && get_next_line(0, &line) > 0)
	{
		if (fill_token(line, mst->token[i++], mst->token_width))
		{
			free(line);
			return (1);
		}
		free(line);
	}
	return (i != mst->token_height);
}

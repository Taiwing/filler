/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:08:19 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/14 12:08:54 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_PARSER_H
# define FILLER_PARSER_H

# include "t_filldata.h"

int	filler_parser(t_filldata *mst);
int	get_player(t_filldata *mst);
int	get_board_dims(t_filldata *mst);
int	get_board(t_filldata *mst);
int	get_token_dims(t_filldata *mst);
int	get_token(t_filldata *mst);

#endif

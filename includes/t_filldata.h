/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_filldata.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:49:01 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/14 11:49:07 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FILLDATA_H
# define T_FILLDATA_H

# define P_O		1
# define P_X		2
# define P_EMPTY	3
# define P_OBS		3

typedef struct	s_filldata
{
	int			board_width;
	int			board_height;
	int			**board;
	int			token_width;
	int			token_height;
	char		**token;
	int			answerx;
	int			answery;
	int			player;
	int			adv;
	int			round;
	int			alone;
}				t_filldata;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_arrays.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:46:20 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/14 11:51:59 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_ARRAYS_H
# define DOUBLE_ARRAYS_H

# include <stddef.h>

void	**alloc_double_array(int x, int y, size_t size);
void	free_double_array(void ***arr);

#endif

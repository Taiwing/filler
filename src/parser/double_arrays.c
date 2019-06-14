/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:39:42 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/14 11:43:18 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "double_arrays.h"

void	**alloc_double_array(int x, int y, size_t size)
{
	void	**arr;
	int		i;

	if (!(arr = (void **)ft_memalloc((y + 1) * sizeof(void *))))
		return (NULL);
	i = 0;
	while (i < y)
	{
		if (!(arr[i++] = (void *)ft_memalloc((x + 1) * size)))
		{
			free_double_array(&arr);
			return (NULL);
		}
	}
	arr[y] = NULL;
	return (arr);
}

void	free_double_array(void ***arr)
{
	void	**ptr;

	ptr = *arr;
	while (*ptr)
		free(*ptr++);
	free(*arr);
	*arr = NULL;
}

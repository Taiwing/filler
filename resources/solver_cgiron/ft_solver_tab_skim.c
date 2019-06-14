/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver_tab_skim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:01:13 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/06 10:30:14 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_solver_tab_skim(t_filler *mf, void (*f)(t_filler *mf, int i, int j))
{
	int i;
	int j;

	j = -1;
	while ((i = -1) && ++j < mf->bszy)
	{
		while (++i < mf->bszx)
		{
			(*f)(mf, i, j);
		}
	}
}

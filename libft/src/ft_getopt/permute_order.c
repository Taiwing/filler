/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permute_order.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:28:23 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/29 04:21:45 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"
#include <stdint.h>

void	permute(uintptr_t *argv, t_optdata *d)
{
	int		i;

	while (d->last_nonopt < d->optind)
	{
		i = d->last_nonopt;
		while (i > d->first_nonopt)
		{
			argv[i - 1] ^= argv[i];
			argv[i] ^= argv[i - 1];
			argv[i - 1] ^= argv[i];
			--i;
		}
		++d->last_nonopt;
		++d->first_nonopt;
	}
}

void	permute_order(int argc, char **argv, t_optdata *d)
{
	if (d->first_nonopt != d->last_nonopt && d->last_nonopt != d->optind)
		permute((uintptr_t *)argv, d);
	else if (d->last_nonopt != d->optind)
		d->first_nonopt = d->optind;
	while (d->optind < argc &&
			(argv[d->optind][0] != '-' || !argv[d->optind][1]))
		++d->optind;
	d->last_nonopt = d->optind;
}

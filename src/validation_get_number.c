/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_get_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:26:32 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:26:33 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_number(t_d *d, long long i, int j, long long minus)
{
	minus = 1;
	if (d->buf[j] == '-' && ++j)
		minus = -1;
	while (d->buf[j] && ft_isdigit(d->buf[j]))
	{
		i = i * 10 + d->buf[j] - '0';
		j++;
		if ((minus < 0 && i > 2147483648) || (minus > 0 && i > 2147483647))
			set_error(d, "ERROR");
	}
	if (d->buf[j] || j == 0)
		set_error(d, "ERROR");
	return ((int)(i * minus));
}

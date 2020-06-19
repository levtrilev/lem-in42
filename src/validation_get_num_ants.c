/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_get_num_ants.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:26:12 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:26:14 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_num_ants(t_d *d)
{
	while (d->num_ants == 0)
	{
		if (get_line(d) == 0)
			set_error(d, "ERROR");
		if (d->buf[0] == '#')
			continue;
		d->num_ants = get_number(d, 0, 0, 0);
		if (d->num_ants <= 0)
			set_error(d, "ERROR");
	}
}

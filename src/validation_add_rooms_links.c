/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_add_rooms_links.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:25:17 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:25:19 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_rooms_links(t_d *d)
{
	int i;

	if (!fill_links_rooms(d))
		return ;
	i = d->two_rooms[0];
	d->two_rooms[0] = d->two_rooms[1];
	d->two_rooms[1] = i;
	fill_links_rooms(d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways_find_short_way.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:21:45 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:21:47 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		wasnt_here(t_d *d, int room, int room_from)
{
	int current_room_from;

	current_room_from = room_from;
	while (current_room_from != d->start)
	{
		if (current_room_from == room)
			return (0);
		current_room_from = d->room_from[current_room_from];
	}
	return (1);
}

void	copy_tmp5_to_tmp4(t_d *d, int i)
{
	while (d->tmp5[i] || d->tmp4[i] || i < (d->n)[5])
	{
		d->tmp4[i] = d->tmp5[i];
		d->tmp5[i] = 0;
		i++;
	}
	(d->n)[4] = (d->n)[5];
	(d->n)[5] = 0;
}

void	set_level_to_rooms(t_d *d, int room)
{
	t_l *tmp;

	tmp = (d->links_rooms)[room];
	while (tmp)
	{
		if (!tmp->del && tmp->allow &&
			((tmp->num_room != d->start && !(d->levels_rooms)[tmp->num_room]) ||
			(((d->levels_rooms)[tmp->num_room] >
			(d->levels_rooms)[room] + tmp->weight) &&
			wasnt_here(d, tmp->num_room, room))))
		{
			(d->levels_rooms)[tmp->num_room] =
					(d->levels_rooms)[room] + tmp->weight;
			(d->room_from)[tmp->num_room] = room;
			if (tmp->num_room != d->end)
				(d->tmp5)[((d->n)[5])++] = tmp->num_room;
		}
		tmp = tmp->next;
	}
}

int		find_shortest_way(t_d *d, int i)
{
	set_level_to_rooms(d, d->start);
	copy_tmp5_to_tmp4(d, 0);
	while ((d->n)[4])
	{
		while (i < (d->n)[4])
			set_level_to_rooms(d, d->tmp4[i++]);
		copy_tmp5_to_tmp4(d, 0);
		i = 0;
	}
	return (0);
}

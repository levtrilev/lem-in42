/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways_write_way.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:22:47 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:22:50 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_way_link(t_d *d, int room)
{
	t_l *tmp;

	tmp = (d->ways)[(d->n)[6]];
	(d->ways)[(d->n)[6]] = (t_l *)malloc(sizeof(t_l));
	(d->ways)[(d->n)[6]]->next = tmp;
	(d->ways)[(d->n)[6]]->num_room = room;
	(d->ways)[(d->n)[6]]->weight = 0;
	(d->ways)[(d->n)[6]]->allow = 0;
	(d->ways)[(d->n)[6]]->del = 0;
}

void	delete_way(t_d *d, t_l *tmp, t_l *next)
{
	tmp = (d->ways)[(d->n)[6]];
	while (tmp->next)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(tmp);
	(d->ways)[(d->n)[6]] = NULL;
}

/*
** (d->n)[6] - current way in d->ways
*/

void	write_way_in_packs_ways(t_d *d, int end)
{
	while (end != d->start)
	{
		create_way_link(d, end);
		end = d->room_from[end];
	}
	create_way_link(d, end);
	if (is_minus_ways(d, NULL, NULL, NULL))
	{
		(d->n)[9] = 1;
		delete_way(d, NULL, NULL);
		back_links_to_original(d);
		ft_bzero(d->levels_rooms, sizeof(int) * (size_t)d->num_rooms);
	}
}

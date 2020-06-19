/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways_set_minus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:22:03 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:22:07 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_l		*get_link(t_d *d, int from, int to)
{
	t_l *tmp;

	tmp = (d->links_rooms)[from];
	while (tmp)
	{
		if (tmp->num_room == to)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	deactive_short_way_and_set_minus(t_d *d, t_l *from, t_l *to)
{
	t_l *link;

	while ((to = to->next))
	{
		link = get_link(d, from->num_room, to->num_room);
		link->allow = 0;
		d->tmp_pointers_links[(d->n[7])++] = link;
		link = get_link(d, to->num_room, from->num_room);
		link->weight = link->num_room == d->start ? 1 : -1;
		d->tmp_pointers_links[(d->n[7])++] = link;
		from = to;
	}
	if (is_use_busy_room(d, (d->ways)[(d->n)[6]],
			(d->ways)[(d->n)[6]], (d->n)[6]))
		delete_cur_way(d, (d->n)[6]--);
}

int		is_minus_ways(t_d *d, t_l *to, t_l *from, t_l *link)
{
	int i;

	i = 0;
	to = (d->ways)[(d->n)[6]];
	from = to;
	while ((to = to->next))
	{
		link = get_link(d, from->num_room, to->num_room);
		if (link->weight < 0)
		{
			i = 1;
			link->del = 1;
			link = get_link(d, to->num_room, from->num_room);
			link->del = 1;
		}
		from = to;
	}
	if (i)
		return (1);
	return (0);
}

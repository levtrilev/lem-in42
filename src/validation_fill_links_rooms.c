/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_fill_links_rooms.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:25:29 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:25:31 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_l		*set_new_link_for_room(t_d *d)
{
	t_l *tmp;

	tmp = (t_l*)malloc(sizeof(t_l));
	tmp->weight = 1;
	tmp->allow = 1;
	tmp->del = 0;
	tmp->next = NULL;
	tmp->num_room = d->two_rooms[1];
	return (tmp);
}

int		fill_links_rooms(t_d *d)
{
	t_l	*tmp;

	if ((tmp = d->links_rooms[d->two_rooms[0]]))
	{
		while (tmp->next)
		{
			if (tmp->num_room == d->two_rooms[1])
				return (0);
			tmp = tmp->next;
		}
		if (tmp->num_room == d->two_rooms[1])
			return (0);
		tmp->next = set_new_link_for_room(d);
	}
	else
		d->links_rooms[d->two_rooms[0]] = set_new_link_for_room(d);
	return (1);
}

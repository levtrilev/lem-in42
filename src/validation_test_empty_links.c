/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_test_empty_links.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:28:01 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:28:03 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_links(t_d *d, int room_from, int room_to)
{
	t_l *tmp;
	t_l *prew;

	tmp = (d->links_rooms)[room_from];
	prew = NULL;
	while (tmp && tmp->num_room != room_to)
	{
		prew = tmp;
		tmp = tmp->next;
	}
	if (tmp && !prew)
	{
		(d->links_rooms)[room_from] = tmp->next;
		free(tmp);
	}
	else if (prew && tmp)
	{
		prew->next = tmp->next;
		free(tmp);
	}
}

int		test_empty_ways(t_d *d, int i, int j, int k)
{
	while (j)
	{
		i = 0;
		j = 0;
		while (i < d->num_rooms)
		{
			if (i != d->start && i != d->end && (d->links_rooms)[i] &&
				!(d->links_rooms)[i]->next && ++j)
			{
				d->n[2]++;
				k = d->links_rooms[i]->num_room;
				delete_links(d, i, k);
				delete_links(d, k, i);
			}
			i++;
		}
	}
	return (0);
}

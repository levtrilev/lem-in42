/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways_del_ways_restore_links.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:21:24 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:21:27 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_cur_way(t_d *d, int i)
{
	t_l *tmp_next;
	t_l *tmp;

	tmp = (d->ways)[i];
	tmp_next = tmp->next;
	while (tmp)
	{
		free(tmp);
		if ((tmp = tmp_next))
			tmp_next = tmp->next;
	}
	(d->ways)[i] = NULL;
}

void	back_links_to_original(t_d *d)
{
	int i;

	i = -1;
	while ((d->tmp_pointers_links)[++i])
	{
		(d->tmp_pointers_links)[i]->weight = 1;
		(d->tmp_pointers_links)[i]->allow = 1;
		(d->tmp_pointers_links)[i] = NULL;
	}
	(d->n)[7] = 0;
}

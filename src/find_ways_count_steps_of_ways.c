/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways_count_steps_of_ways.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:20:01 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:20:07 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** i - number current way
** t_fa - fast link of way
** t_sl - slow link of way
*/

int		is_use_busy_room(t_d *d, t_l *t_fa, t_l *t_sl, int i)
{
	int k;

	while ((t_sl = t_sl->next) && t_sl->num_room != d->end)
	{
		k = 0;
		while (i - ++k >= 0 && (t_fa = (d->ways)[i - k]))
		{
			if (t_fa->weight > 1000000)
				continue ;
			while ((t_fa = t_fa->next) && t_fa->num_room != d->end)
				if (t_sl->num_room == t_fa->num_room)
					return (1);
		}
	}
	return (0);
}

/*
** weight - long way
** allow - max long way in pack
*/

int		count_steps_of_ways(t_d *d, int i, int num_pack)
{
	t_l *tmp;
	int step;

	step = 0;
	while ((d->ways)[++i] || (d->ways)[i + 1])
	{
		if (!(d->ways)[i] && i > 0)
			num_pack++;
		else
		{
			tmp = (d->ways)[i];
			tmp->allow = num_pack;
			step = 0;
			while ((tmp = tmp->next) && ++((d->ways)[i]->weight))
				tmp->del = ++step;
		}
	}
	catch_shortest_pack_of_ways(d, i, 0);
	return (1);
}

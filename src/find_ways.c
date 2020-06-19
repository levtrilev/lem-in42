/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:13:12 by couida            #+#    #+#             */
/*   Updated: 2020/02/22 19:13:15 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	fill_arr_n(t_d *d)
{
	int i;

	i = 0;
	while ((d->ways)[i] || (d->ways)[i + 1])
	{
		(d->n)[i] = (d->ways)[i] ? (d->ways)[i]->weight : -1;
		i++;
	}
}

/*
** count steps in pack
*/

int		c_steps(t_d *d, int iend, int istart, int i)
{
	int num_ants;
	int num_steps;

	num_steps = 0;
	num_ants = d->num_ants;
	while (num_ants > 0 && ++num_steps)
	{
		i = istart;
		while (i <= iend)
		{
			if (((d->n)[i])-- <= 0)
				num_ants--;
			i++;
		}
	}
	return (num_steps);
}

void	remove_other_packs(t_d *d, int i)
{
	int j;

	j = 0;
	while ((d->ways)[i] || (d->ways)[i + 1])
	{
		if (!(d->ways)[i] && ++i)
			continue ;
		if ((d->ways)[i]->allow != d->c_pack)
			delete_cur_way(d, i);
		else if (d->c_pack != 0)
		{
			(d->ways)[j] = (d->ways)[i];
			(d->ways)[i] = NULL;
			j++;
		}
		i++;
	}
}

/*
** fill_arr_n(d, i, 0); set number steps of ways in temp arr
** (d->n)[0] = 0; // index of shortest pack of ways
** (d->n)[1] = 0; // index of start element of pack ways
** (d->n)[2] = 0; // index of last element of pack ways
** (d->n)[3] = 0; // index of temp way
*/

int		catch_shortest_pack_of_ways(t_d *d, int i, int k)
{
	ft_bzero(d->n, sizeof(int) * (i + 100));
	fill_arr_n(d);
	d->c_steps = 1000000000;
	while ((d->ways)[d->c_end] || (d->ways)[d->c_end - 1])
	{
		if (!(d->ways)[d->c_end])
		{
			k = c_steps(d, d->c_end - 1, d->c_start, 0);
			if (k < d->c_steps)
			{
				d->c_steps = k;
				d->c_pack = (d->ways)[d->c_end - 1]->allow;
			}
			d->c_start = d->c_end + 1;
		}
		d->c_end++;
	}
	remove_other_packs(d, 0);
	return (0);
}

void	find__ways(t_d *d)
{
	while (1)
	{
		find_shortest_way(d, 0);
		if (!(d->levels_rooms)[d->end] && !((d->ways)[0]))
			set_error(d, "ERROR");
		else if (!(d->levels_rooms)[d->end] && ++((d->n)[6]))
			break ;
		write_way_in_packs_ways(d, d->end);
		if ((d->n)[9] && !((d->n)[9] = 0) && ++((d->n)[6]))
		{
			if ((d->n)[6] > 3000)
				break ;
			continue;
		}
		deactive_short_way_and_set_minus(d, (d->ways)[(d->n)[6]],
				(d->ways)[(d->n)[6]]);
		ft_bzero(d->levels_rooms, sizeof(int) * (size_t)d->num_rooms);
		++((d->n)[6]);
	}
	count_steps_of_ways(d, -1, 0);
}

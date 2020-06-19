/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_set_room_name.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:27:45 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:27:47 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_cript_number(const char *str)
{
	int i;
	int res;

	i = -1;
	res = 0;
	while (str[++i])
		res += LEN_ARRS / str[i] + str[i] * i + i * 7 + res * 3;
	res = res % (LEN_ARRS - 1);
	res = res > 0 ? res : res * -1;
	return (res);
}

void	set_room_alpha(t_d *d, t_n *tmp)
{
	t_n *tmp_pre;

	(d->n)[5000] = 0;
	while (tmp)
	{
		tmp_pre = tmp;
		if (ft_strequ(d->buf, d->rooms_names[tmp->num_room]))
			set_error(d, "ERROR Duplicate room name");
		tmp = tmp->next;
		if (++((d->n)[5000]) > (d->n)[5001])
			(d->n)[5001] = (d->n)[5000];
	}
	tmp_pre->next = ft_memalloc(sizeof(t_n));
	tmp_pre->next->num_room = d->num_rooms;
	tmp_pre->next->next = NULL;
}

void	test_unique_coordinates(t_d *d, int i)
{
	while (i < d->num_rooms)
	{
		if (d->x_rooms[i] == d->x_rooms[d->num_rooms] &&
			d->y_rooms[i] == d->y_rooms[d->num_rooms])
			set_error(d, "ERROR Not unique location of room.");
		i++;
	}
}

void	set_room_name(t_d *d, int i, int j)
{
	t_n *tmp;

	j = get_cript_number(d->buf);
	i++;
	tmp = d->rooms_alphabet[j];
	if (!(d->rooms_names[d->num_rooms] = ft_strdup(d->buf)))
		set_error(d, "ERROR Can not alloc memory");
	if (!d->rooms_alphabet[j])
	{
		d->rooms_alphabet[j] = ft_memalloc(sizeof(t_n));
		d->rooms_alphabet[j]->num_room = d->num_rooms;
		d->rooms_alphabet[j]->next = NULL;
	}
	else
		set_room_alpha(d, tmp);
	test_unique_coordinates(d, 0);
}

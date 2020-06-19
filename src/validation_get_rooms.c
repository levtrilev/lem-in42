/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_get_rooms.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:26:42 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:26:44 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_room(t_d *d, int i, int k)
{
	if ((d->n)[0] == 1 && (d->n)[0]++)
		d->start = d->num_rooms;
	if ((d->n)[1] == 1 && (d->n)[1]++)
		d->end = d->num_rooms;
	i = ft_strlen(d->buf);
	while ((ft_isdigit(d->buf[--i]) || d->buf[i] == '-') && i >= 0 && ++k)
		if (d->buf[i] == '-')
			break ;
	if (i == 0 || (d->buf[i] != ' ' && d->buf[i] != '-') || k == 0)
		set_error(d, "ERROR wrong input or error with numbers");
	k = 0;
	i = d->buf[i] == '-' ? i - 1 : i;
	d->y_rooms[d->num_rooms] = get_number(d, 0, i + 1, 0);
	d->buf[i] = '\0';
	while ((ft_isdigit(d->buf[--i]) || d->buf[i] == '-') && i >= 0 && ++k)
		if (d->buf[i] == '-')
			break ;
	if (i == 0 || (d->buf[i] != ' ' && d->buf[i] != '-') || k == 0)
		set_error(d, "ERROR wrong input or error with numbers");
	i = d->buf[i] == '-' ? i - 1 : i;
	d->x_rooms[d->num_rooms] = get_number(d, 0, i + 1, 0);
	d->buf[i] = '\0';
	set_room_name(d, 0, 0);
	d->num_rooms++;
}

int		is_room2(t_d *d, char *buf, int j)
{
	t_n *tmp;

	j = get_cript_number(buf);
	tmp = d->rooms_alphabet[j];
	while (tmp)
	{
		if (ft_strequ(d->rooms_names[tmp->num_room], buf))
		{
			d->two_rooms[1] = tmp->num_room;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		is_rooms(t_d *d, int n, int j)
{
	t_n *tmp;

	d->buf[n] = '\0';
	j = get_cript_number(d->buf);
	tmp = d->rooms_alphabet[j];
	while (tmp)
	{
		if (ft_strequ(d->rooms_names[tmp->num_room], d->buf))
		{
			d->two_rooms[0] = tmp->num_room;
			if (is_room2(d, &d->buf[n + 1], 0))
			{
				d->buf[n] = '-';
				return (1);
			}
		}
		tmp = tmp->next;
	}
	d->buf[n] = '-';
	return (0);
}

int		test_string_on_valid_link(t_d *d, int n)
{
	while (d->buf[n])
	{
		if (d->buf[n] == 'L' && (n == 0 || d->buf[n - 1] == '-'))
		{
			set_error(d, "ERROR The room cannot be called with the first L");
		}
		if (d->buf[n] == '-' && is_rooms(d, n, 0))
			return (1);
		n++;
	}
	return (0);
}

void	get_rooms(t_d *d)
{
	while (get_line(d) > 0)
	{
		if (ft_strequ(d->buf, KEY_START_ROOM))
		{
			if ((d->n)[0])
				set_error(d, "ERROR ##start can be only once.");
			++((d->n)[0]);
		}
		else if (ft_strequ(d->buf, KEY_END_ROOM))
		{
			if ((d->n)[1])
				set_error(d, "ERROR ##end can be only once.");
			++((d->n)[1]);
		}
		else if (d->buf[0] == KEY_ICON_COMMENT)
			continue;
		else if (test_string_on_valid_link(d, 0))
			break ;
		else
			get_room(d, 0, 0);
		if (d->num_rooms > LEN_ARRS - 2)
			set_error(d, "ERROR Too much rooms!");
	}
}

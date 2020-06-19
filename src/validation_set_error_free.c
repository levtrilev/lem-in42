/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_set_error_free.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:27:33 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:27:36 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	clear_lists(t_l *tmp, t_l *tmp_next)
{
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
}

void	clear_ways(t_d *d, int i)
{
	while ((d->ways)[i])
		delete_cur_way(d, i++);
	free(d->links_rooms);
	free(d->x_rooms);
	free(d->y_rooms);
	free(d->tmp4);
	free(d->tmp5);
	free(d->tmp_pointers_links);
	free(d->levels_rooms);
	free(d->rooms_names);
	free(d->room_from);
	free(d->rooms_alphabet);
}

void	clear_alphabet(t_n *tmp, t_n *tmp_next)
{
	while (tmp)
	{
		tmp_next = tmp->next;
		free(tmp);
		tmp = tmp_next;
	}
}

void	free_data(t_d *d, int i, int j)
{
	while (i < d->num_rooms)
	{
		(d->rooms_names)[i] ? free((d->rooms_names)[i]) : "";
		clear_lists(d->links_rooms[i], NULL);
		i++;
	}
	while (j < LEN_ARRS)
	{
		if (d->rooms_alphabet[j])
			clear_alphabet(d->rooms_alphabet[j], NULL);
		j++;
	}
	free(d->input_str);
	clear_ways(d, 0);
}

void	set_error(t_d *d, char *str_error)
{
	free_data(d, 0, 0);
	write(2, str_error, ft_strlen(str_error));
	write(2, "\n", 1);
	exit(0);
}

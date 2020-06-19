/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:27:12 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:27:14 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_null(t_d *d)
{
	ft_bzero(d->links_rooms, sizeof(t_l*) * LEN_ARRS);
	ft_bzero(d->y_rooms, sizeof(int) * LEN_ARRS);
	ft_bzero(d->x_rooms, sizeof(int) * LEN_ARRS);
	ft_bzero(d->tmp4, sizeof(int) * LEN_ARRS);
	ft_bzero(d->tmp5, sizeof(int) * LEN_ARRS);
	ft_bzero(d->tmp_pointers_links, sizeof(t_l*) * LEN_ARRS);
	ft_bzero(d->ways, sizeof(t_l*) * LEN_ARRS_LOC);
	ft_bzero(d->levels_rooms, sizeof(int) * LEN_ARRS);
	ft_bzero(d->rooms_names, sizeof(char*) * LEN_ARRS);
	ft_bzero(d->n, sizeof(int) * LEN_ARRS_LOC);
	ft_bzero(d->room_from, sizeof(int) * LEN_ARRS);
	ft_bzero(d->rooms_alphabet, sizeof(t_n*) * LEN_ARRS);
}

void	init(t_d *d)
{
	d->end = -1;
	d->start = -1;
	ft_bzero(d, sizeof(*d));
	if (!((d->links_rooms =
			(t_l **)malloc(sizeof(t_l*) * LEN_ARRS)) &&
			(d->x_rooms = (int*)malloc(sizeof(int) * LEN_ARRS)) &&
			(d->y_rooms = (int*)malloc(sizeof(int) * LEN_ARRS)) &&
			(d->tmp4 = (int*)malloc(sizeof(int) * LEN_ARRS)) &&
			(d->tmp5 = (int*)malloc(sizeof(int) * LEN_ARRS)) &&
			(d->tmp_pointers_links =
					(t_l**)malloc(sizeof(t_l*) * LEN_ARRS)) &&
			(d->levels_rooms = (int*)malloc(sizeof(int) * LEN_ARRS)) &&
			(d->rooms_names = (char**)malloc(sizeof(char*) * LEN_ARRS)) &&
			(d->room_from = (int*)malloc(sizeof(int) * LEN_ARRS)) &&
			(d->rooms_alphabet = (t_n**)malloc(sizeof(t_n*) * LEN_ARRS))))
		exit(2);
	set_null(d);
}

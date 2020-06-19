/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_get_links.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:25:56 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:25:58 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_links_from_input(t_d *d)
{
	add_rooms_links(d);
	while (get_line(d) > 0)
	{
		if (d->buf[0] == KEY_ICON_COMMENT)
			continue ;
		if (!test_string_on_valid_link(d, 0))
			return (0);
		if (d->two_rooms[0] != d->two_rooms[1])
			add_rooms_links(d);
	}
	return (0);
}

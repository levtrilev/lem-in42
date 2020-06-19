/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_parse_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:27:22 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:27:23 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		parse_input(t_d *d)
{
	get_num_ants(d);
	get_rooms(d);
	if (d->start == -1 || d->end == -1)
		set_error(d, "ERROR Start or End room not found.");
	if (d->num_rooms == 0)
		set_error(d, "ERROR Where are rooms? Number of rooms = 0.");
	get_links_from_input(d);
	if (get_line(d) > 0)
		set_error(d, "ERROR in links");
	if (get_link(d, d->start, d->end))
		print_all_in_one_step(d);
	//test_empty_ways(d, 0, 1, 0);
	return (1);
}

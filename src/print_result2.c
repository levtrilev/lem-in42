/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:24:35 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:25:04 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_all_in_one_step(t_d *d)
{
	int i;

	write(1, d->input_str, d->len_input_str);
	write(1, "\n", 1);
	i = 0;
	while (++i <= d->num_ants)
	{
		write(1, "L", 1);
		ft_putnbr_end(i, '-');
		ft_putstr_end((d->rooms_names)[d->end], 0);
		i == d->num_ants ? write(1, "\n", 1) : write(1, " ", 1);
	}
	free_data(d, 0, 0);
	exit(0);
}

void	copy_ways(t_d *d, int i)
{
	while ((d->ways)[i])
		i++;
	(d->n)[0] = i;
	i = 0;
	while (i < d->n[0])
	{
		(d->ways)[i]->allow = 0;
		(d->ways)[i + d->n[0]] = (d->ways)[i];
		i++;
	}
}

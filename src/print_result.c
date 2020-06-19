/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:24:35 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:25:04 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** numa - number ants
** numw - number ways
** for shorter records
** (d->ways)[i]->allow = number ants in this way
*/

void	fill_numbers_ants_to_ways(t_d *d, int i, int numa, int numw)
{
	t_l *tmp;

	copy_ways(d, 0);
	while (numa && !(i = 0))
		while (i < d->n[0] && numa)
		{
			tmp = (d->ways)[numw + i]->next;
			if (!tmp)
			{
				((d->ways)[i]->allow)++;
				numa--;
			}
			else
				(d->ways)[numw + i] = tmp;
			i++;
		}
	while ((d->ways)[numw])
		((d->ways)[numw++]) = NULL;
}

void	print_ways(t_d *d, t_l *tmp, int i, int j)
{
	int k;

	k = 0;
	while (++i < (d->n)[0])
	{
		tmp = (d->ways)[i];
		while ((tmp = tmp->next))
		{
			if (tmp->allow)
			{
				if (j++)
					write(1, " ", 1);
				write(1, "L", 1);
				ft_putnbr_end(tmp->allow, '-');
				ft_putstr_end((d->rooms_names)[tmp->num_room], 0);
				k++;
			}
		}
	}
	if (k)
		write(1, "\n", 1);
}

/*
** weight = num ant if step (del) > 0
*/

int		fill_first_room(t_d *d, int way, t_l *tmp)
{
	d->n[1] = tmp->allow;
	if (((d->ways)[way]->allow)-- > 0)
	{
		tmp->allow = ++((d->n)[2]);
		d->n[3] = 1;
	}
	else
		tmp->allow = 0;
	return (1);
}

void	run_way(t_d *d, int i, int way, t_l *tmp)
{
	tmp = (d->ways[way]);
	while ((tmp = tmp->next))
	{
		if (tmp->del == 1 && fill_first_room(d, way, tmp))
			continue;
		i = tmp->allow;
		tmp->allow = d->n[1];
		if (i || d->n[1])
			d->n[3] = 1;
		d->n[1] = i;
	}
	d->n[1] = 0;
}

void	print_result(t_d *d, int i)
{
	ft_bzero(d->n, sizeof(int) * 1000);
	while ((d->ways)[i])
		i++;
	(d->n)[0] = i;
	write(1, d->input_str, d->len_input_str);
	if (d->input_str[d->len_input_str - 1] != '\n')
		write(1, "\n\n", 2);
	else
		write(1, "\n", 1);
	fill_numbers_ants_to_ways(d, 0, d->num_ants, (d->n)[0]);
	d->n[3] = 1;
	while (d->n[3])
	{
		d->n[3] = 0;
		i = -1;
		while (++i < d->n[0])
			run_way(d, 0, i, NULL);
		print_ways(d, NULL, -1, 0);
	}
}

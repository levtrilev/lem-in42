/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:24:24 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:24:27 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_d		d;

	init(&d);
	d.fd = 0;
	parse_input(&d);
	find__ways(&d);
	print_result(&d, 0);
	free_data(&d, 0, 0);
	return (0);
}
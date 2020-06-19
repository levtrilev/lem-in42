/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_get_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:25:43 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:25:45 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_input(t_d *d, int i, int n)
{
	char *str;

	str = NULL;
	if (!(str = (char *)malloc(sizeof(char) * LEN_STR)))
		set_error(d, "ERROR can't allocate memory");
	ft_bzero(str, sizeof(char) * LEN_STR);
	while ((n = read(0, &(str[i]), LEN_STR)) && (i + 10000 < LEN_STR))
	{
		i += n;
		if (i > 60)
			break ;
	}
	if (!i || i + 10000 > LEN_STR)
	{
		free(str);
		set_error(d, "ERROR");
	}
	str[i] = '\0';
	d->input_str = str;
	d->len_input_str = i;
}

int		get_one_line(t_d *d, int i)
{
	static int n = 0;

	while (n < LEN_STR)
	{
		(d->buf)[i] = (d->input_str)[n++];
		if ((d->buf)[i] == '\n')
		{
			(d->buf)[i] = '\0';
			if (i == 0 && (d->input_str)[n - 2] == '\n')
				set_error(d, "ERROR in end of input data");
			return (i);
		}
		else if ((d->buf)[i] == '\0')
		{
			n = LEN_ARRS;
			return (i);
		}
		i++;
	}
	return (0);
}

int		get_line(t_d *d)
{
	static int was_read = 0;

	if (!was_read++)
		read_input(d, 0, 0);
	return (get_one_line(d, 0));
}

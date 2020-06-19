/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:23:38 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:23:41 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *b, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)b;
	while (n > 0)
	{
		n--;
		tmp[n] = 0;
	}
}

void	ft_putstr_end(char *str, char end_symbol)
{
	int i;

	i = ft_strlen(str);
	if (end_symbol)
	{
		str[i] = end_symbol;
		write(1, str, i + 1);
		str[i] = '\0';
	}
	else
		write(1, str, i);
}

void	ft_putnbr_end(int n, char end_symbol)
{
	long long	nb;
	char		c;

	nb = (1 - 2 * (n < 0)) * (long long)n;
	if (n < 0)
		write(1, "-", 1);
	if (nb > 9)
		ft_putnbr_end(nb / 10, 0);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	if (end_symbol)
		write(1, &end_symbol, 1);
}

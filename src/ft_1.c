/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: couida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 15:23:14 by couida            #+#    #+#             */
/*   Updated: 2020/05/15 15:23:19 by couida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp_s1;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	if ((tmp_s1 = (char *)malloc(sizeof(char) * (i + 1))))
	{
		tmp_s1[i] = '\0';
		while (i-- > 0)
			tmp_s1[i] = s1[i];
		return (tmp_s1);
	}
	else
		return (NULL);
}

void	*ft_memalloc(size_t size)
{
	char *p;

	p = (char *)malloc(size);
	if (!p)
		return (NULL);
	while (size > 0)
	{
		size--;
		p[size] = '\0';
	}
	return (p);
}

int		ft_strequ(char const *s1, char const *s2)
{
	size_t i;

	i = 0;
	if (s1 || s2)
	{
		if ((s1 && !s2) || (!s1 && s2))
			return (0);
		else
		{
			while (s1[i] && s2[i] && s1[i] == s2[i])
				i++;
			if (s1[i] == s2[i])
				return (1);
			else
				return (0);
		}
	}
	else
		return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:44:00 by mel-kabb          #+#    #+#             */
/*   Updated: 2022/10/28 12:48:57 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	int		j;
	char	*t;
	char	d;

	j = 0;
	t = (char *)str;
	d = (char)c;
	i = 0;
	if (d == 0)
	{
		while (t[i])
			i++;
		return (&t[i]);
	}
	while (t[i])
	{
		if (t[i] == d)
			return (&t[i]);
		i++;
	}
	return (0);
}

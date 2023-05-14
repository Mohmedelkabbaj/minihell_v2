/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:40:16 by mel-kabb          #+#    #+#             */
/*   Updated: 2022/10/21 17:14:02 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*t;
	int				j;
	char			d;

	j = 0;
	i = ft_strlen((char *)s);
	t = (unsigned char *)s;
	d = (char)c;
	if (d == 0)
	{
		while (t[i])
			i++;
		return (&((char *)t)[i]);
	}
	while (i--)
	{
		if (t[i] == d)
			return (&((char *)t)[i]);
	}
	return (0);
}

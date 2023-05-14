/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:54:47 by mel-kabb          #+#    #+#             */
/*   Updated: 2022/10/23 22:34:38 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		j;
	int		i;

	j = 0;
	i = start;
	if (!s)
		return (0);
	if (start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *)s) - start)
	{
		len = ft_strlen((char *)s) - start;
	}
	p = malloc(len + 1);
	if (!p)
	{
		return (0);
	}
	while (start < len + i && s[start] != '\0')
	{
		p[j++] = s[start++];
	}
	p[j] = '\0';
	return (p);
}

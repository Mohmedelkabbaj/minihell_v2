/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:38:00 by mel-kabb          #+#    #+#             */
/*   Updated: 2022/10/28 15:33:57 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search(char s, char const *st)
{
	int	i;

	i = 0;
	while (st[i])
	{
		if (s == st[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		len;
	int		j;

	j = 0;
	i = 0;
	p = 0;
	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(""));
	len = ft_strlen((char *)s1);
	while (s1[i] && search(s1[i], set))
		i++;
	len--;
	while (s1[len] && search(s1[len], set))
		len--;
	if (len < i)
		return (ft_strdup(""));
	p = ft_substr(s1, i, len - i + 1);
	return (p);
}

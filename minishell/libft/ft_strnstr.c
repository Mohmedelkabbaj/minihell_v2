/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:43:51 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/04/05 00:58:56 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!len && *needle)
	{
		return (0);
	}
	if (needle[i] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[j])
	{
		i = 0;
		while (needle[i] && needle[i] == haystack[j + i] && j + i < len)
		{
			i++;
			if ((char)needle[i] == '\0')
				return ((char *)&haystack[j]);
		}
		j++;
	}
	return (0);
}

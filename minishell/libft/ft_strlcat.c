/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:43:08 by mel-kabb          #+#    #+#             */
/*   Updated: 2022/10/24 15:53:26 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	total;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (!dst && !dstsize)
		return (i);
	while (dst[j])
		j++;
	if (j <= dstsize)
		total = i + j;
	else
		return (i + dstsize);
	i = 0;
	while (src[i] && j + 1 < dstsize)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (total);
}

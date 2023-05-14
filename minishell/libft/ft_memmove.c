/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:48:40 by mel-kabb          #+#    #+#             */
/*   Updated: 2022/10/29 19:39:08 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!src && !dst)
		return (0);
	if (src == dst)
		return (dst);
	if (src > dst)
	{
		i = 0;
		while (i < len)
		{
			((char *)(dst))[i] = ((char *)(src))[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i--)
		{
			((char *)(dst))[i] = ((char *)(src))[i];
		}
	}
	return (dst);
}

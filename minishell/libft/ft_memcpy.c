/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:10:08 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/04/02 02:24:17 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (0);
	if (src == dst)
		return (dst);
	while (i < n)
	{
		((char *)(dst))[i] = ((char *)(src))[i];
		i++;
	}
	return (dst);
}

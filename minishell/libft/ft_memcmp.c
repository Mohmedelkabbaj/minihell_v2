/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:02:47 by mel-kabb          #+#    #+#             */
/*   Updated: 2022/10/29 19:38:56 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)(s1))[i] != ((unsigned char *)(s2))[i])
			return (((unsigned char *)(s1))[i] - (((unsigned char *)(s2))[i]));
		i++;
	}
	return (0);
}

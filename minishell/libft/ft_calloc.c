/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:17:57 by mel-kabb          #+#    #+#             */
/*   Updated: 2022/10/29 20:19:42 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	char	*p;

	i = 0;
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (0);
	ft_bzero(p, size * count);
	return (p);
}

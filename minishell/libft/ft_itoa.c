/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:32:56 by mel-kabb          #+#    #+#             */
/*   Updated: 2022/10/24 19:39:48 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int n)
{
	int		size;
	long	xb;

	size = 0;
	xb = n;
	if (xb == 0)
		size++;
	if (xb < 0)
		size++;
	while (xb)
	{
		xb /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	i;
	char	*p;
	int		l;

	l = ft_count(n);
	p = malloc(l + 1);
	if (!p)
		return (0);
	i = n;
	if (i == 0)
		p[0] = '0';
	p[1] = '\0';
	if (i < 0)
	{
		p[0] = '-';
		i *= -1;
	}
	while (i > 0)
	{
		p[--l] = i % 10 + '0';
		i /= 10;
	}
	p[ft_count(n)] = '\0';
	return (p);
}

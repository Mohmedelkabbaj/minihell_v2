/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:36:48 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/05/10 21:53:13 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int				i;
	int j;
	char	*d;

	d = s2;
	i = 0;
	if(!s2 && s1)
		return (ft_strdup(s1));
	if(!s1 && s2)
	{
		return (ft_strdup(s2));
	}
	p = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2);
	while(s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = i;
	p[j] = ' ';
	j = j + 1;
	i = 0;
	while(s2[i])
	{
		p[j++] = s2[i++];
	}
	p[j] = '\0';
	return (p);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*p;
	int				i;
	int j;
	char	*d;

	d = s2;
	i = 0;
	if(!s2 && s1)
		return (ft_strdup(s1));
	if(!s1 && s2)
	{
		return (ft_strdup(s2));
	}
	p = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2);
	while(s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while(s2[i])
	{
		p[j++] = s2[i++];
	}
	p[j] = '\0';
	return (p);
}

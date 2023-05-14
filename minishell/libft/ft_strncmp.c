/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:04:25 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/04/05 00:51:45 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *first, char *second, size_t length)
{
	size_t	i;

	i = 0;
	while ((i < length) && ((char)first[i] != '\0'
			|| (char)second[i] != '\0'))
	{
		if ((char)first[i] < (char)second[i])
		{
			return (-1);
		}
		else if ((char)first[i] > (char)second[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

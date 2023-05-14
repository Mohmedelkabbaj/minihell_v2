/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:27:56 by mel-kabb          #+#    #+#             */
/*   Updated: 2022/10/21 17:00:11 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int arx)
{
	if ((arx >= '0' && arx <= '9') || (arx >= 'a' && arx <= 'z') || (arx >= 'A'
			&& arx <= 'Z'))
	{
		return (1);
	}
	return (0);
}

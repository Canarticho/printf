/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 08:24:40 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/04 17:51:37 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ustoa(uint16_t s, char *buffer, int base)
{
	int			i;
	char		str[2 * 8 + 2];
	uint16_t	tmp;

	ft_bzero(str, 2 * 8 + 2);
	i = 0;
	while (s / base)
	{
		tmp = s % base;
		str[i++] = (tmp >= 10) ? (tmp - 10 + 'a') : (tmp + '0');
		s = s / base;
	}
	tmp = s % base;
	str[i++] = (tmp % base >= 10) ? (tmp - 10 + 'a') : (tmp + '0');
	str[i] = '\0';
	return (ft_strcpy(buffer, ft_strrev(str)));
}

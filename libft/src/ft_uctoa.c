/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 08:24:40 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/04 17:51:28 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uctoa(unsigned char c, char *buffer, int base)
{
	int				i;
	char			str[8 + 2];
	int				neg;
	unsigned char	tmp;

	neg = 0;
	ft_bzero(str, 8 + 2);
	i = 0;
	tmp = 0;
	while (c / base)
	{
		tmp = c % base;
		str[i++] = (tmp >= 10) ? (tmp - 10 + 'a') : (tmp + '0');
		c = c / base;
	}
	tmp = c % base;
	str[i++] = (c % base >= 10) ? (tmp - 10 + 'a') : (tmp + '0');
	if (neg == 1)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strcpy(buffer, ft_strrev(str)));
}

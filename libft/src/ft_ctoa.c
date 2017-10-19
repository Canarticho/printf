/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 08:24:40 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/15 15:51:21 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctoa(char c, char *buffer, int base)
{
	int		i;
	char	str[8 + 2];
	char	tmp;

	ft_bzero(str, 8 + 2);
	i = 0;
	tmp = 0;
	while (c / base)
	{
		tmp = (c % base > 0) ? (c % base) : -(c % base);
		str[i++] = (tmp >= 10) ? (tmp - 10 + 'a') : (tmp + '0');
		c = c / base;
	}
	tmp = (c % base > 0) ? (c % base) : -(c % base);
	str[i++] = (c % base >= 10) ? (tmp - 10 + 'a') : (tmp + '0');
	if (c < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strcpy(buffer, ft_strrev(str)));
}

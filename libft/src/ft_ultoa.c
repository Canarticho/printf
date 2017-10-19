/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 08:24:40 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/04 17:52:00 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa(uint64_t l, char *buffer, int base)
{
	int			i;
	char		str[8 * 8 + 2];
	int			neg;
	uint64_t	tmp;

	neg = 0;
	ft_bzero(str, 8 * 8 + 2);
	i = 0;
	tmp = 0;
	while (l / base)
	{
		tmp = l % base;
		str[i++] = (tmp >= 10) ? (tmp - 10 + 'a') : (tmp + '0');
		l = l / base;
	}
	tmp = l % base;
	str[i++] = (l % base >= 10) ? (tmp - 10 + 'a') : (tmp + '0');
	if (neg == 1)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strcpy(buffer, ft_strrev(str)));
}

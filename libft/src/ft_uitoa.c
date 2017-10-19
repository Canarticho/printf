/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:55:04 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/15 13:58:39 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(uint32_t n, char *buffer, int base)
{
	int			i;
	char		str[4 * 8 + 2];
	uint32_t	tmp;

	ft_bzero(str, 4 * 8 + 2);
	i = 0;
	tmp = 0;
	while (n / base)
	{
		tmp = n % base;
		str[i++] = (tmp >= 10) ? (tmp - 10 + 'a') : (tmp + '0');
		n = n / base;
	}
	tmp = n % base;
	str[i++] = (tmp % base >= 10) ? (tmp - 10 + 'a') : (tmp + '0');
	str[i] = '\0';
	return (ft_strcpy(buffer, ft_strrev(str)));
}

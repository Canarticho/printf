/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 08:24:40 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/04 17:52:09 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa(uint64_t ll, char *buffer, int base)
{
	int		i;
	char	str[8 * 8 + 2];
	int64_t	tmp;

	ft_bzero(str, 8 * 8 + 2);
	i = 0;
	tmp = 0;
	while (ll / base)
	{
		tmp = ll % base;
		str[i++] = (tmp >= 10) ? (tmp - 10 + 'a') : (tmp + '0');
		ll = ll / base;
	}
	tmp = ll % base;
	str[i++] = (tmp >= 10) ? (tmp - 10 + 'a') : (tmp + '0');
	str[i] = '\0';
	return (ft_strcpy(buffer, ft_strrev(str)));
}

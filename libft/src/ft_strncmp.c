/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:29:57 by chle-van          #+#    #+#             */
/*   Updated: 2016/11/28 08:58:00 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)(s1[i]) ==
			(unsigned char)(s2[i]) && i < len)
		i++;
	if (i == len)
		return (0);
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

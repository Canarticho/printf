/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 04:17:03 by chle-van          #+#    #+#             */
/*   Updated: 2016/11/28 07:04:18 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *str;
	char *tmp;

	if (!(tmp = malloc(sizeof(char) * len + 1)) || !s)
		return (NULL);
	str = tmp;
	while (len--)
		*(tmp++) = s[start++];
	*tmp = '\0';
	return (str);
}

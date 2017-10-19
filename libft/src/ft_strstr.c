/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:36:37 by chle-van          #+#    #+#             */
/*   Updated: 2016/11/17 00:13:34 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *b, const char *s)
{
	int j;

	j = 0;
	if (!(*s))
		return ((char *)b);
	while (*b)
	{
		while (b[j] == s[j] && s[j] && b[j])
			j++;
		if (!s[j])
			return ((char *)b);
		j = 0;
		b++;
	}
	return (NULL);
}

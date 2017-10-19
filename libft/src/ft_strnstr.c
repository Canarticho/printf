/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:36:37 by chle-van          #+#    #+#             */
/*   Updated: 2016/11/28 09:28:07 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *s, size_t n)
{
	size_t j;

	j = 0;
	if (!(*s) || b == s)
		return ((char *)b);
	while (*b && n)
	{
		while (b[j] == s[j] && s[j] && b[j] && j < n)
		{
			j++;
		}
		if (!s[j])
			return ((char *)b);
		j = 0;
		b++;
		n--;
	}
	return (NULL);
}

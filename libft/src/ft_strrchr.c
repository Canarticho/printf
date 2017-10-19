/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:30:28 by chle-van          #+#    #+#             */
/*   Updated: 2016/11/28 08:33:39 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int end;
	int i;

	i = 0;
	end = ft_strlen((char *)s);
	while (i <= end)
	{
		if ((char)s[end - i] == (char)c)
			return ((char *)&s[end - i]);
		i++;
	}
	return (NULL);
}

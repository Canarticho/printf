/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 04:26:27 by chle-van          #+#    #+#             */
/*   Updated: 2016/11/28 11:36:31 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*tmp;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!(tmp = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_strlcat(ft_strcpy(tmp, s1), s2, size);
	return (tmp);
}

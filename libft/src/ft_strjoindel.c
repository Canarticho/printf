/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 02:26:27 by chle-van          #+#    #+#             */
/*   Updated: 2017/02/07 07:28:27 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoindel(char *s1, char *s2)
{
	char	*tmp;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!(tmp = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_strlcat(ft_strcpy(tmp, s1), s2, size);
	free(s1);
	free(s2);
	return (tmp);
}

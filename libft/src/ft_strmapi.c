/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 03:11:00 by chle-van          #+#    #+#             */
/*   Updated: 2016/11/28 11:35:13 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	int		i;
	int		size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen((char *)s);
	if (!(tmp = malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = -1;
	while (++i < size)
		tmp[i] = (f)(i, (char)s[i]);
	tmp[size] = '\0';
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 03:11:00 by chle-van          #+#    #+#             */
/*   Updated: 2016/11/28 11:34:20 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;
	int		size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen((char *)s);
	i = -1;
	if (!(tmp = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (++i < size)
		tmp[i] = (f)((char)s[i]);
	tmp[size] = '\0';
	return (tmp);
}

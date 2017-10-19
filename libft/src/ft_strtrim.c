/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 04:38:17 by chle-van          #+#    #+#             */
/*   Updated: 2016/11/28 11:37:06 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str;
	int		j;

	if (!s)
		return (NULL);
	while (ft_isspace(*s))
	{
		s++;
		if (!*s)
			return (ft_strndup(s, 0));
	}
	j = ft_strlen(s);
	while ((ft_isspace(s[j - 1])) && j > 0)
		j--;
	if (!(str = ft_strndup(s, j)))
		return (NULL);
	return (str);
}

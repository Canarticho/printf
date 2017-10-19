/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 23:13:46 by chle-van          #+#    #+#             */
/*   Updated: 2017/02/22 01:42:33 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *tmp;

	if (!(tmp = ft_strnew(ft_strlen((char *)s))))
		return (NULL);
	tmp = ft_strcpy(tmp, s);
	return (tmp);
}

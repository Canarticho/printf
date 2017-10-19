/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtowcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:42:55 by chle-van          #+#    #+#             */
/*   Updated: 2017/05/24 19:10:45 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_strtowcs(char *src)
{
	wchar_t		*wcs;
	size_t		i;

	i = -1;
	wcs = ft_wcsnew(ft_strlen(src));
	while (src[++i])
		wcs[i] = src[i];
	return (wcs);
}

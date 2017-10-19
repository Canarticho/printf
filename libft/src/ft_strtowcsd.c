/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtowcsd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:42:55 by chle-van          #+#    #+#             */
/*   Updated: 2017/05/29 01:09:27 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_strtowcsd(char *src)
{
	wchar_t		*wcs;
	size_t		i;

	i = -1;
	wcs = ft_wcsnew(ft_strlen(src));
	while (src[++i])
		wcs[i] = (wchar_t)src[i];
	ft_strdel(&src);
	return (wcs);
}

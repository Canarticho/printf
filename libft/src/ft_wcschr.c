/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcschr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:03:32 by chle-van          #+#    #+#             */
/*   Updated: 2017/05/24 19:12:20 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wcschr(const wchar_t *wcs, wchar_t wc)
{
	while (*wcs)
	{
		if (*wcs == wc)
			return ((wchar_t *)wcs);
		wcs++;
	}
	return (NULL);
}

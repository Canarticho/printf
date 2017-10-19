/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:58:25 by chle-van          #+#    #+#             */
/*   Updated: 2017/05/27 23:05:47 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcsnew(size_t size)
{
	wchar_t	*tmp;

	tmp = malloc(sizeof(wchar_t) * (size + 1));
	ft_bzero((char *)tmp, (size + 1) * sizeof(wchar_t));
	return (tmp);
}

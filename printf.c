/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:16:32 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/20 16:32:14 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				ft_printf(const char *s, ...)
{
	va_list			args;
	int				i;
	size_t			size;

	size = 0;
	va_start(args, s);
	while ((i = ft_strchr(s, '%') - s) >= 0 && *(s + 1))
	{
		ft_addbuff((char *)s, i, 0);
		s += i;
		size += i;
		size += ft_getarg((char **)&s, args);
	}
	if (*s != '%')
		i = ft_strlen(s);
	else
		i = 0;
	ft_addbuff((char *)s, i, FLUSH);
	return (size + i);
}

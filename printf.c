/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:16:32 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/23 10:04:17 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t			ft_noarg(char **s, t_type type)
{
	size_t res;

	type.size = 1;
	res = (type.size < type.min_range) ? (type.min_range) : (1);
	if (type.min_range > 1)
	{
		if (!(type.padflags & 4))
		{
			ft_set_min_range_chars(type, type.min_range - 1);
			ft_addbuff(*s, 1, 0);
		}
		else if (type.padflags & 4)
		{
			ft_addbuff(*s, 1, 0);
			ft_set_min_range_chars(type, type.min_range - 1);
		}
	}
	else
		ft_addbuff(*s, 1, 0);
	(*s)++;
	return (res);
}

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

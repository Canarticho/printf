/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:25:14 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/23 09:45:28 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t			ft_wchar(t_type type, va_list args)
{
	wchar_t	wc;
	wchar_t	*tmp;

	if (type.format == 'c')
	{
		wc = (wchar_t)va_arg(args, wchar_t);
		type.osize = 1;
		type.size = ft_co_wchar(&wc, type.osize, type);
		return (ft_padding_wchars(type, &wc));
	}
	else
	{
		tmp = va_arg(args, wchar_t *);
		if (!tmp)
			type.size = 0;
		else
		{
			type.osize = ft_wcslen(tmp);
			type.size = ft_co_wchar(tmp, type.osize, type);
		}
		return (ft_padding_wchars(type, tmp));
	}
	return (0);
}

size_t			ft_conv_char(t_type type, va_list args)
{
	char	*tmp;
	char	c;

	if (type.mod > 3)
		return (ft_wchar(type, args));
	else if (type.format == 's')
	{
		tmp = (char *)va_arg(args, char *);
		if (!tmp)
			type.size = 0;
		else
			type.size = ft_strlen(tmp);
		return (ft_padding_chars(type, tmp));
	}
	else if (type.format == 'c')
	{
		c = (char)va_arg(args, int);
		type.size = 1;
		return (ft_padding_chars(type, &c));
	}
	return (0);
}

size_t			ft_conv_ptr(t_type type, va_list args)
{
	char	tmp[16];

	type.size = 0;
	ft_bzero(tmp, 16);
	type.unsign.l = ((long)va_arg(args, long));
	ft_ultoa(type.unsign.l, tmp, 16);
	if (type.unsign.l == 0 && type.pp && !type.prec)
		type.size = 0;
	else
		type.size = ft_strlen(tmp);
	type.padflags = type.padflags | 1;
	return (ft_padding_number(tmp, type) + type.size);
}

size_t			ft_doublep(t_type type, va_list list)
{
	size_t	res;
	char	str[2];

	str[0] = '%';
	str[1] = '\0';
	type.size = 1;
	res = 1;
	if (list)
		;
	if (!(type.padflags & 4))
	{
		res += ft_set_number_field(type, 0);
		ft_sendbuff('%', 1);
	}
	else
	{
		ft_sendbuff('%', 1);
		res += ft_set_number_field(type, 0);
	}
	return (res);
}

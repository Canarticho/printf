/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:25:14 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/18 07:21:41 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t			ft_wchar(t_type type, va_list args)
{
	wchar_t	wc;
	wchar_t	*tmp;

	if (type.format == 'C')
	{
		wc = (wchar_t)va_arg(args, wchar_t);
		type.size = 1;
		return (ft_padding_wchars(type, &wc, 0));
	}
	else
	{
		tmp = (wchar_t *)va_arg(args, wchar_t *);
		type.size = ft_wcslen(tmp);
	}
	return (ft_padding_wchars(type, tmp, 0));
}

size_t			ft_conv_char(t_type type, va_list args)
{
	char	*tmp;
	char	c;

	if (type.mod > 3 || ft_strchr("SC", type.format))
		return (ft_wchar(type, args));
	else if (type.format == 's')
	{
		tmp = (char *)va_arg(args, char *);
		type.size = ft_strlen(tmp);
		return (ft_padding_chars(type, tmp, 0));
	}
	else
	{
		c = (char)va_arg(args, int);
		type.size = 1;
		return (ft_padding_chars(type, &c, 0));
	}
}

size_t			ft_conv_ptr(t_type type, va_list args)
{
	char	tmp[16];

	type.size = 0;
	ft_bzero(tmp, 16);
	type.unsign.l = ((long)va_arg(args, long));
	ft_ultoa(type.unsign.l, tmp, 16);
	if (type.unsign.l != 0/* && type.pp && !type.prec*/)
		type.size = ft_strlen(tmp);
	type.padflags = type.padflags | 1;
	return (type.size + ft_padding_number(tmp, type));
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

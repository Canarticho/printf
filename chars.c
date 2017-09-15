/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:25:14 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/15 14:45:29 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t			ft_wchar(t_type type, va_list args)
{
	wchar_t	wc;
	wchar_t	*tmp;

	if (type.format == 'c' || type.format == 'C')
	{
		wc = (wchar_t)va_arg(args, wchar_t);
		type.size = 1;
		return (ft_padding_chars(type, &wc, 0));
	}
	else
	{
		tmp = (wchar_t *)va_arg(args, wchar_t *);
		type.size = ft_wcslen(tmp);
	}
	return (ft_padding_chars(type, tmp, 0));
}

size_t			ft_conv_char(t_type type, va_list args)
{
	char	*tmp;

	if (type.mod > 3 || ft_strchr("SCc", type.format))
		return (ft_wchar(type, args));
	else
	{
		tmp = (char *)va_arg(args, char *);
		type.size = ft_strlen(tmp);
	}
	return (ft_padding_chars(type, ft_strtowcs(tmp), FREE));
}

size_t			ft_conv_ptr(t_type type, va_list args)
{
	char	tmp[16];
	size_t	ptr;

	ptr = ((int)va_arg(args, int));
	tmp[0] = '0';
	tmp[1] = 'x';
	ft_ulltoa((long long)ptr, tmp + 2, 16);
	type.size = ft_strlen(tmp);
	ft_addbuff(tmp, type.size, 0);
	return (type.size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:41:00 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/15 14:04:13 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			ft_prep_unsign(char format)
{
	int			base;

	base = 0;
	if (format == 'u')
		base = 10;
	else if (format == 'o')
		base = 8;
	else if (format == 'x' || format == 'X')
		base = 16;
	return (base);
}

char				*ft_prep_var(t_type type)
{
	static t_pvar var[5] = 
	{
		{1, ft_pctoa},
		{2, ft_pstoa},
		{3, ft_pitoa},
		{4, ft_pltoa},
		{5, ft_plltoa}
	};
	int i;

	i = -1;
	while (++i < 5)
		if (type.mod == var[i].mod)
			return (var[i].ft_var(type, ft_prep_unsign(type.format)));
	return (NULL);
}

size_t				ft_conv_signed(t_type type, va_list list)
{
	char *res;

	if (type.mod == 1)
		type.sign.c = (char)va_arg(list, int);
	else if (type.mod == 2)
		type.sign.s = (short)va_arg(list, int);
	else if (type.mod == 3)
		type.sign.i = (int)va_arg(list, int);
	else if (type.mod == 4)
		type.sign.l = (long)va_arg(list, long);
	else if (type.mod == 5)
		type.sign.ll = (long long)va_arg(list, long long);
	if (type.mod == 7)
		type.mod = 4;
	else if (type.mod == 6)
		type.mod = 5;
	res = ft_prep_var(type);
	type.size = ft_strlen(res);
	return (ft_padding_number(ft_strtowcs(res), type) + type.size);
}


size_t				ft_conv_unsigned(t_type type, va_list list)
{
	char	*res;
	int		i;

	i = -1;
	if (type.mod == 1)
		type.unsign.c = (char)va_arg(list, int);
	else if (type.mod == 2)
		type.unsign.s = (short)va_arg(list, int);
	else if (type.mod == 3)
		type.unsign.i = (int)va_arg(list, int);
	else if (type.mod == 4)
		type.unsign.l = (long)va_arg(list, long);
	else if (type.mod == 5)
		type.unsign.ll = (long long)va_arg(list, long long);
	if (type.mod == 7)
		type.mod = 4;
	if (type.mod == 6)
		type.mod = 5;
	res = ft_prep_var(type);
	type.size = ft_strlen(res);
	while (res[++i] && type.format == 'X')
		res[i] = ft_toupper(res[i]);
	return (ft_padding_number(ft_strtowcs(res), type) + type.size);
}

size_t				ft_convsp(t_type type, va_list list)
{
	if (type.mod == 6)
	{
		if (ft_strchr("di", type.format))
			type.sign.im = (intmax_t)va_arg(list, intmax_t);
		else if (ft_strchr("ouxX", type.format))
			type.unsign.um = (uintmax_t)va_arg(list, uintmax_t);
	}
	else if (type.mod == 7)
	{
		if (ft_strchr("di", type.format))
			type.sign.sst = (ssize_t)va_arg(list, ssize_t);
		else if (ft_strchr("ouxX", type.format))
			type.unsign.st = (size_t)va_arg(list, size_t);
	}
	if (ft_strchr("di", type.format))
		return (ft_conv_signed(type, list));
	if (ft_strchr("ouxX", type.format))
		return (ft_conv_unsigned(type, list));
	return(0);
}

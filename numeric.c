/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:41:00 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/03 15:36:11 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char			*ft_prep_sign(t_type arg)
{
	char		res[16 * 8 + 2];
	long long	llm;

	llm = -1;
	ft_bzero(res, 16 * 8 + 2);
	if (arg.sign.ll > 0)
		return (ft_ulltoa(arg.sign.ll, res, 10));
	else
	{
		arg.sign.ll = llm ^ arg.sign.ll + 1;
		res[0] = '-';
	}
	return (ft_ulltoa(arg.sign.l, res + 1, 10));
}

size_t				ft_conv_signed(t_type type, va_list list)
{
	char *res;

	if (type.mod == 1)
		type.sign.s = (char)va_arg(list, int);
	else if (type.mod == 2)
		type.sign.c = (short)va_arg(list, int);
	else if (type.mod == 3)
		type.sign.i = (int)va_arg(list, int);
	else if (type.mod == 4)
		type.sign.l = (long)va_arg(list, long);
	else if (type.mod == 5)
		type.sign.ll = (long long)va_arg(list, long long);
	res = ft_prep_sign(type);
	type.size = ft_strlen(res);
	return (ft_padding_number(ft_strtowcs(res), type) + type.size);
}

static char			*ft_prep_unsign(t_type arg)
{
	int		base;
	char	res[16 * 8 + 2];

	ft_bzero(res, 16 * 8 + 2);
	base = 0;
	if (arg.format == 'u')
		base = 10;
	else if (arg.format == 'o')
		base = 8;
	else if (arg.format == 'x' || arg.format == 'X')
		base = 16;
	return (ft_ulltoa(arg.unsign.ll, res, base));
}

size_t				ft_conv_unsigned(t_type type, va_list list)
{
	char *res;

	if (type.mod == 1)
		type.unsign.c = (char)va_arg(list, int);
	else if (type.mod == 2)
		type.unsign.ll = (short)va_arg(list, int);
	else if (type.mod == 3)
		type.unsign.ll = (int)va_arg(list, int);
	else if (type.mod == 4)
		type.unsign.ll = (long)va_arg(list, long);
	else if (type.mod == 5)
		type.unsign.ll = (long long)va_arg(list, long long);
	res = ft_prep_unsign(type);
	type.size = ft_strlen(res);
	return (ft_padding_number(ft_strtowcs(res), type) + type.size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 08:33:40 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/23 10:47:26 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t		ft_reste(wchar_t c, char *res)
{
	size_t	len;

	len = 0;
	res[len++] = 0xFC | (c >> 30);
	res[len++] = 0x80 | ((c >> 24) & 0x3F);
	res[len++] = 0x80 | ((c >> 18) & 0x3F);
	res[len++] = 0x80 | ((c >> 12) & 0x3F);
	res[len++] = 0x80 | ((c >> 6) & 0x3F);
	res[len++] = 0x80 | (c & 0x3F);
	res[len] = 0;
	return (len);
}

static size_t		ft_4bchar(wchar_t c, char *res)
{
	size_t	len;

	len = 0;
	if (c < 0x200000)
	{
		res[len++] = 0xF0 | (c >> 18);
		res[len++] = 0x80 | ((c >> 12) & 0x3F);
		res[len++] = 0x80 | ((c >> 6) & 0x3F);
		res[len++] = 0x80 | (c & 0x3F);
	}
	else if (c < 0x4000000)
	{
		res[len++] = 0xF8 | (c >> 24);
		res[len++] = 0x80 | ((c >> 18) & 0x3F);
		res[len++] = 0x80 | ((c >> 12) & 0x3F);
		res[len++] = 0x80 | ((c >> 6) & 0x3F);
		res[len++] = 0x80 | (c & 0x3F);
	}
	else
		return (ft_reste(c, res));
	res[len] = 0;
	return (len);
}

static size_t		ft_2bchar(wchar_t c, char *res)
{
	size_t	len;

	len = 0;
	if (c < 0x80)
		res[len++] = c;
	else if (c < 0x800)
	{
		res[len++] = 0xC0 | (c >> 6);
		res[len++] = 0x80 | (c & 0x3F);
	}
	else if (c < 0x10000)
	{
		res[len++] = 0xE0 | (c >> 12);
		res[len++] = 0x80 | ((c >> 6) & 0x3F);
		res[len++] = 0x80 | (c & 0x3F);
	}
	res[len] = 0;
	return (len);
}

size_t				ft_co_wchar(wchar_t *c, size_t size, t_type type)
{
	size_t	i;
	char	*res;

	i = -1;
	type.size = 0;
	if (!(res = ft_strnew(BUFF_SIZE)))
		return (0);
	while (++i < type.osize && !(type.strsize = 0))
	{
		if (c[i] < 0x200000 && i < type.osize)
			type.strsize = ft_2bchar(c[i], res + type.size);
		else if (i < type.osize)
			type.strsize = ft_4bchar(c[i], res + type.size);
		type.size += type.strsize;
		if (type.pp && type.size > type.prec)
			break ;
	}
	if (type.size > type.prec && type.pp)
		type.size -= type.strsize;
	if (size == (size_t)-1)
		ft_addbuff(res, type.size, FREE);
	else
		free(res);
	return (type.size);
}

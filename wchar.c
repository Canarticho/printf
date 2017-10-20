/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 08:33:40 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/20 15:35:21 by chle-van         ###   ########.fr       */
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
	size_t	plusize;
	size_t i;
	char	*res;
	size_t totsize;

	i = -1;
	totsize = 0;
	if (!(res = ft_strnew(BUFF_SIZE)))
		return (0);
	while (++i < type.osize)
	{
		plusize = 0;
		if (c[i] < 0x200000)
			plusize = ft_2bchar(c[i], res + totsize);
		else
			plusize = ft_4bchar(c[i], res + totsize);
		if (totsize > type.prec && type.pp)
		{
			ft_addbuff(res, totsize - plusize, FREE);
			return (0);
		}
		totsize += plusize;
	}
	if (size == (size_t)-1)
		ft_addbuff(res, totsize, FREE);
	else 
		free(res);
	return (totsize);
}

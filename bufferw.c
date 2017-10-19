/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:16:32 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/19 10:34:19 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	ft_wcharalign(wchar_t src, char *res)
{
	size_t	size;
	char	*tmp;

	tmp = (char *)&src;
	size = 0;
	if (src & 4034953344)
		size = 4;
	else if (src & 14712960)
		size = 3;
	else if (src & 49280)
		size = 2;
	else if (!(src & 128))
		size = 1;
	if (size)
		ft_memcpy(res, &src, size);
	return (size);
}

void			ft_sendbuffw(wchar_t c, int size)
{
	wchar_t	wcs[BUFF_SIZE];
	int		i;

	ft_bzero(wcs, BUFF_SIZE * sizeof(wchar_t));
	i = 0;
	while (size && i < BUFF_SIZE)
	{
		wcs[i] = (wchar_t)c;
		i++;
		if (i == BUFF_SIZE || i == size)
		{
			ft_addbuffw(wcs, i, 0);
			if ((size -= i))
				ft_sendbuffw(c, size);
		}
	}
}

static void		ft_clearw(size_t size, wchar_t *res)
{
	size_t	newsize;
	char	newres[BUFF_SIZE * sizeof(wchar_t)];
	size_t	i;

	i = -1;
	newsize = 0;
	ft_bzero(newres, BUFF_SIZE * sizeof(wchar_t));
	while (++i < size)
	{
		newsize += ft_wcharalign(res[i], newres + newsize);
	}
	write(1, newres, newsize);
	ft_bzero(res, newsize);
}

void			ft_addbuffw(wchar_t *src, size_t size, char flag)
{
	static wchar_t			res[BUFF_SIZE];
	static size_t			offset;

	if (flag == SWAP && offset)
	{
		ft_clearw(offset, res);
		offset = 0;
		return ;
	}
	ft_addbuff(NULL, 0, SWAP);
	if (size < BUFF_SIZE - offset)
	{
		ft_memcpy(res + offset, src, size * sizeof(wchar_t));
		offset += size;
	}
	else
	{
		ft_memcpy(res + offset, src, (BUFF_SIZE - offset) * sizeof(wchar_t));
		ft_clearw(BUFF_SIZE, res);
		size -= BUFF_SIZE - offset;
		offset = 0;
		if (size)
			ft_addbuffw(src + BUFF_SIZE, size, flag);
	}
	if (flag & FLUSH || flag & SWAP)
	{
		ft_clearw(offset, res);
		offset = 0;
	}
	if (flag & FREE)
		ft_wcsdel((wchar_t **)&src);
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

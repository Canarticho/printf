/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 16:16:32 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/15 14:37:12 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_sendbuff(char c, int size)
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
			ft_addbuff(wcs, i, 0);
			if ((size -= i))
				ft_sendbuff(c, size);
		}
	}
}

static void	ft_clear(size_t size, wchar_t *res)
{
	write(1, res, size * sizeof(wchar_t));
	ft_bzero(res, (size_t)BUFF_SIZE * sizeof(wchar_t));
}

void		ft_addbuff(void *src, size_t size, char flag)
{
	static wchar_t			res[BUFF_SIZE];
	static size_t			offset;

	if (size < BUFF_SIZE - offset)
	{
		ft_memcpy(res + offset, src, size * sizeof(wchar_t));
		offset += size;
	}
	else
	{
		ft_memcpy(res + offset, src, BUFF_SIZE - offset);
		ft_clear(BUFF_SIZE, res);
		size -= BUFF_SIZE - offset;
		offset = 0;
		if (size)
			ft_addbuff(src + BUFF_SIZE, size, flag);
	}
	if (flag & FLUSH)
	{
		ft_clear(offset, res);
		offset = 0;
	}
	if (flag & FREE)
		ft_wcsdel((wchar_t **)&src);
}

int			ft_printf(const char *s, ...)
{
	va_list			args;
	int				i;
	size_t			size;

	size = 0;
	va_start(args, s);
	while ((i = ft_strchr(s, '%') - s) >= 0)
	{
		ft_addbuff(ft_strtowcsd(ft_strndup(s, i)), i, FREE);
		s += i;
		size += i;
		if (!(*(s + 1) == '%'))
			size += ft_getarg((char **)&s, args);
		else
		{
			ft_addbuff(L"%", 1, 0);
			s += 2;
			size++;
		}
	}
	i = ft_strlen(s);
	ft_addbuff(ft_strtowcsd(ft_strndup(s, i)), i, FREE + FLUSH);
	return (size + i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 00:45:25 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/19 10:34:02 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_sendbuff(char c, int size)
{
	char	s[BUFF_SIZE];
	int		i;

	ft_bzero(s, BUFF_SIZE * sizeof(char));
	i = 0;
	while (size && i < BUFF_SIZE)
	{
		s[i] = (char)c;
		i++;
		if (i == BUFF_SIZE || i == size)
		{
			ft_addbuff(s, i, 0);
			if ((size -= i))
				ft_sendbuff(c, size);
		}
	}
}

static void	ft_clear(size_t size, char *res)
{
	write(1, res, size * sizeof(char));
	ft_bzero(res, (size_t)BUFF_SIZE * sizeof(char));
}

void		ft_addbuff(char *src, size_t size, char flag)
{
	static char		res[BUFF_SIZE];
	static size_t	offset;

	if (flag == SWAP)
	{
		ft_clear(offset, res);
		offset = 0;
		return ;
	}
	ft_addbuffw(NULL, 0, SWAP);
	if (size < BUFF_SIZE - offset)
	{
		ft_memcpy(res + offset, src, size * sizeof(char));
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
	if (flag & FLUSH || flag & SWAP)
	{
		ft_clear(offset, res);
		offset = 0;
	}
	if (flag & FREE)
		ft_strdel((char **)&src);
}

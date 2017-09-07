/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:40:20 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/04 19:13:55 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_pad_diez(char type, wchar_t *str)
{
	if (ft_strchr("X", type))
	{
		ft_addbuff(L"0X", 2, 0);
		return (2);
	}
	if (ft_strchr("x", type))
	{
		ft_addbuff(L"0x", 2, 0);
		return (2);
	}
	if (type == 'o' && *str != '0')
	{
		ft_addbuff(L"0", 1, 0);
		return (1);
	}
	return (0);
}

static int	ft_set_number_prec(t_type type)
{
	int size;
	int padsize;

	size = 0;
	if ((padsize = type.prec - type.size) > 0)
	{
		ft_sendbuff('0', padsize);
		size += padsize;
	}
	return (size);
}

size_t		ft_set_number_field(t_type type, wchar_t *str)
{
	int padsize;
	int soust;
	int red;
	int size;

	soust = (type.prec > type.size) ? (type.prec) : (type.size);
	red = (type.padflags & 24) ? (1) : (0);
	size = 0;
	if ((type.format == 'x' || type.format == 'X') && type.padflags & 1)
		soust += 2;
	if (((type.format == 'd' || type.format == 'i') && type.padflags & 8 &&
				str[0] == '-') || (type.format == 'o' && type.padflags & 1))
		soust++;
	if ((padsize = type.min_range - soust) > 0)
	{
		if (type.padflags & 2)
			ft_sendbuff('0', padsize - red);
		else
			ft_sendbuff(' ', padsize - red);
		size = padsize - red;
	}
	return (size);
}

int			ft_padding_number(wchar_t *str, t_type type)
{
	int size;

	size = 0;
	if (str[0] == '-' && type.padflags & 2)
		ft_sendbuff('-', 1);
	if (type.prec && type.padflags & 2)
		type.padflags -= 2;
	if ((type.padflags & 8) && ft_strchr("di", type.format) &&
			str[0] != '-' && (type.padflags & 2))
	{
		ft_sendbuff('+', 1);
		size++;
	}
	if (!(type.padflags & 4))
		size += ft_set_number_field(type, str);
	if ((type.padflags & 1) && ft_strchr("oxX", type.format))
		size += ft_pad_diez(type.format, str);
	if ((type.padflags & 8) && ft_strchr("di", type.format) &&
			str[0] != '-' && !(type.padflags & 2))
	{
		ft_sendbuff('+', 1);
		size++;
	}
	else if ((type.padflags & 16) && ft_strchr("aAdeEfFgGi", type.format))
	{
		ft_sendbuff(' ', 1);
		size++;
	}
	if (type.prec > type.size)
		size += ft_set_number_prec(type);
	if (str[0] == '-' && type.padflags & 2)
		ft_addbuff(str + 1, type.size, 0);
	ft_addbuff(str, type.size, 0);
	if ((type.padflags & 4))
		size += ft_set_number_field(type, str);
	return (size);
}

ft_padding_signed(wchar_t *str, t_type type)
{

}

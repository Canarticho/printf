/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:40:20 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/18 07:26:37 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_pad_diez(char type, char *str, int *neg)
{
	if (ft_strchr("X", type) && *str != '0')
	{
		ft_addbuff("0X", 2, 0);
		return (*neg = 2);
	}
	if ((ft_strchr("x", type) && *str != '0') || type == 'p')
	{
		ft_addbuff("0x", 2, 0);
		return (*neg = 2);
	}
	if (type == 'o')
	{
		ft_addbuff("0", 1, 0);
		return (*neg = 1);
	}
	return (0);
}

static size_t	ft_padding_signbis(char *str, t_type type, size_t size, int neg)
{
	if ((type.padflags & 8 && str[0] != '-' && !(type.padflags & 2)) ||
			(str[0] == '-' && neg == 0 && type.pp))
		neg++;
	if (!(type.padflags & 4))
		size += ft_set_number_field(type, neg);
	if ((type.padflags & 8) && str[0] != '-' && !(type.padflags & 2))
	{
		ft_sendbuff('+', 1);
		size++;
	}
	size += ft_set_number_prec(type);
	if (str[0] == '-' && (type.padflags & 2 || type.prec >= type.size))
		ft_addbuff(str + 1, type.size - 1, 0);
	else
		ft_addbuff(str, type.size, 0);
	if ((type.padflags & 4))
		size += ft_set_number_field(type, neg);
	return (size);
}

static size_t	ft_padding_signed(char *str, t_type type)
{
	size_t	size;
	int		neg;

	neg = 0;
	size = 0;
	if ((!type.sign.ll && !type.unsign.ll && type.pp && !type.prec))
		return (ft_set_number_field(type, 0));
	if ((type.padflags & 8) && str[0] != '-' && (type.padflags & 2))
	{
		ft_sendbuff('+', 1);
		size++;
		neg++;
	}
	if ((type.padflags & 16) && str[0] != '-' && !(type.padflags & 2))
	{
		ft_sendbuff(' ', 1);
		size++;
		neg++;
	}
	if (str[0] == '-' && (type.padflags & 2 || type.prec >= type.size))
		ft_sendbuff(*str, 1);
	return (ft_padding_signbis(str, type, size, neg));
}

static size_t	ft_padding_unsigned(char *str, t_type type)
{
	int size;
	int neg;

	neg = 0;
	size = 0;
	if (type.format == 'p')
		ft_pad_diez(type.format, str, &neg);
	if ((!(type.sign.ll || type.unsign.ll) && (type.pp && !type.prec)) &&
			!(type.padflags & 1 && type.format == 'o') && type.format != 'p')
		return (ft_set_number_field(type, 0));
	if (!(type.padflags & 4) && !(type.padflags & 2))
		size += ft_set_number_field(type, neg);
	if (type.padflags & 1 && ft_strchr("oxX", type.format))
		size += ft_pad_diez(type.format, str, &neg);
	if (!(type.padflags & 4) && (type.padflags & 2))
		size += ft_set_number_field(type, neg);
	size += ft_set_number_prec(type);
//	if (type.format != 'p' && type.pp && !type.prec)
		ft_addbuff(str, type.size, 0);
	if ((type.padflags & 4))
		size += ft_set_number_field(type, neg);
	return (size);
}

size_t			ft_padding_number(char *str, t_type type)
{
	int size;

	size = 0;
	if (type.pp && type.padflags & 2)
		type.padflags -= 2;
	if (ft_strchr("di", type.format))
		size = ft_padding_signed(str, type);
	else
		size = ft_padding_unsigned(str, type);
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:40:20 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/17 04:25:37 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_pad_diez(char type, char *str, int *neg)
{
	if (ft_strchr("X", type) && *str != '0')
	{
		ft_addbuff("0X", 2, 0);
		return (*neg = 2);
	}
	if (ft_strchr("x", type) && *str != '0')
	{
		ft_addbuff("0x", 2, 0);
		return (*neg = 2);
	}
	if (type == 'o' && *str != '0')
	{
		ft_addbuff("0", 1, 0);
		return (*neg = 1);
	}
	return (0);
}

static int	ft_set_number_prec(t_type type, int neg)
{
	int size;
	int padsize;

	size = 0;
	if ((padsize = type.prec - type.size) > 0 && neg)
	{
		ft_sendbuff('0', padsize);
		size += padsize;
	}
	else if ((padsize = type.prec - type.size) > 0)
	{
		ft_sendbuff('0', padsize);
		size += padsize;
	}
	return (size);
}

size_t		ft_set_number_field(t_type type, char *str, int neg)
{
	int padsize;
	int soust;
//	int red;
	int size;

	if (!str)
		return (0);
	soust = (type.prec > type.size) ? (type.prec) : (type.size);
	soust = (type.padflags & 24) ? (soust + 1 + neg) : (soust + neg);
	size = 0;
	if ((type.format == 'x' || type.format == 'X') && type.padflags & 1 && !neg)
		soust += 2;
	if (type.format == 'o' && type.padflags & 1 && !neg)
		soust += 1;
	if ((padsize = type.min_range - soust) > 0)
	{
		if (type.padflags & 2)
			ft_sendbuff('0', padsize);
		else
			ft_sendbuff(' ', padsize);
		size = padsize ;
	}
	return (size);
}

static size_t		ft_padding_signed(char *str, t_type type)
{
	size_t	size;
	int		neg;
	char	*tmp;

	tmp = str;
	neg = 0;
	size = 0;
	if ((!type.sign.ll && !type.unsign.ll && type.pp && !type.prec))
		return (ft_set_number_field(type, str, 0));
	if (str[0] == '-' && ((type.padflags & 2) || type.prec > size + 1))
	{
		ft_sendbuff(*str++, 1);
	}		
	if ((type.padflags & 8) && tmp[0] != '-' && (type.padflags & 2))
	{
		ft_sendbuff('+', 1);
		size++;
		neg++;
	}
	if ((type.padflags & 16) && tmp[0] != '-' && !(type.padflags & 2))
	{
		ft_sendbuff(' ', 1);
		size++;
		neg++;
	}
	if (!(type.padflags & 4))
		size += ft_set_number_field(type, str, 0);
	if ((type.padflags & 8) && tmp[0] != '-' && !(type.padflags & 2))
	{
		ft_sendbuff('+', 1);
		size++;
		neg++;
	}
	size += ft_set_number_prec(type, neg);
	if (str[0] == '-' && type.padflags & 2)
		ft_addbuff(str + 1, type.size, 0);
	else
		ft_addbuff(str, type.size, 0);
	if ((type.padflags & 4))
		size += ft_set_number_field(type, str, 0);
	return (size);
}

static size_t		ft_padding_unsigned(char *str, t_type type)
{
	int size;
	int neg;

	neg = 0;
	size = 0;
	if (!type.sign.ll && !type.unsign.ll && type.pp && !type.prec &&
		   !(type.padflags & 1 && type.format == 'o'))
		return (ft_set_number_field(type, str, 0));
	if (!(type.padflags & 4) && !(type.padflags & 2))
		size += ft_set_number_field(type, str, neg);
	if ((type.padflags & 1) && ft_strchr("oxX", type.format))
		size += ft_pad_diez(type.format, str, &neg);
	if (!(type.padflags & 4) && (type.padflags & 2))
		size += ft_set_number_field(type, str, neg);
	size += ft_set_number_prec(type, 0);
	ft_addbuff(str, type.size, 0);
	if ((type.padflags & 4))
		size += ft_set_number_field(type, str, neg);
	return (size);
}

size_t			ft_padding_number(char *str, t_type type)
{
	int size;

	size = 0;
	if (type.pp && type.padflags & 2)
		type.padflags -= 2;
	if (ft_strchr("di",type.format))
		size = ft_padding_signed(str, type);
	else
		size = ft_padding_unsigned(str, type);
	return (size);
}

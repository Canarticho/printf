/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 07:08:26 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/08 16:24:55 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_padflags(char **s, t_type *type)
{
	int		tmp;

	tmp = 0;
	while (ft_strchr("#0-+ ", **s))
	{
		if (**s == '#')
			tmp = 1;
		else if (**s == '0')
			tmp = 2;
		else if (**s == '-')
			tmp = 4;
		else if (**s == '+')
			tmp = 8;
		else if (**s == ' ')
			tmp = 16;
		type->padflags = type->padflags | tmp;
		tmp = 0;
		(*s)++;
	}
	if ((type->padflags & 6) == 6)
		type->padflags -= 2;
	if ((type->padflags & 24) == 24)
		type->padflags -= 16;
}

static void	ft_prec(char **s, t_type *type)
{
	int		i;
	char	tmp[20];

	type->prec = 0;
	type->min_range = 0;
	i = 0;
	while (ft_isdigit(*(*s + i)))
		i++;
	ft_bzero(tmp, 20);
	type->min_range = ft_atoi(ft_strncpy(tmp, *s, i));
	*s += i;
	i = 0;
	if (**s == '.')
	{
		ft_bzero(tmp, 20);
		++(*s);
		while (ft_isdigit(*(*s + i)))
			i++;
		type->prec = ft_atoi(ft_strncpy(tmp, *s, i));
		*s += i;
	}
}

size_t		ft_getarg(char **s, va_list args)
{
	t_type	type;
	size_t	totalsize;

	totalsize = 0;
	(*s)++;
	type.mod = 3;
	ft_padflags(s, &type);
	ft_prec(s, &type);
	while (ft_strchr("hl", **s) && type.mod < 6 && type.mod > 0)
		type.mod = (*((*s)++) == 'l') ? (type.mod + 1) : (type.mod - 1);
	if (**s && ft_strchr("DOUXdiouxSsCcp", **s))
	{
		type.format = **s;
		if (**s && ft_strchr("DOUSC", **s))
		{
			type.mod++;
			ft_tolower(type.format);
		}
		totalsize += ft_converter(type, args);
		(*s)++;
	}
	return (totalsize);
}

size_t		ft_converter(t_type type, va_list list)
{
	size_t			i;
	static t_pconv	conv[9] =
	{
		{'d', ft_conv_signed},
		{'i', ft_conv_signed},
		{'o', ft_conv_unsigned},
		{'u', ft_conv_unsigned},
		{'x', ft_conv_unsigned},
		{'X', ft_conv_unsigned},
		{'s', ft_conv_char},
		{'c', ft_conv_char},
		{'p', ft_conv_ptr}
	};

	type.sign.ll = 0;
	type.unsign.ll = 0;
	i = -1;
	while (++i < 11)
		if (type.format == conv[i].letter)
			return (conv[i].ft_conv(type, list));
	return (0);
}

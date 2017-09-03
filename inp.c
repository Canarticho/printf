/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 07:08:26 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/03 17:26:55 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	ft_padflags(char **s)
{
	char	flags;
	int		tmp;

	flags = 0;
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
		flags = flags | tmp;
		tmp = 0;
		(*s)++;
	}
	if ((flags & 6) == 6)
		flags -= 2;
	if ((flags & 24) == 24)
		flags -= 16;
	return (flags);
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
	type.padflags = ft_padflags(s);
	ft_prec(s, &type);
	while (ft_strchr("hl", **s) && type.mod < 5 && type.mod > 0)
		type.mod = (*((*s)++) == 'l') ? (++type.mod) : (--type.mod);
	if (**s && ft_strchr("DOUX", **s))
	{
		type.mod++;
		ft_tolower(**s);
	}
	if (**s && ft_strchr("diouxSsCcp", **s))
	{
		type.format = **s;
		totalsize += ft_converter(type, args);
		(*s)++;
	}
	return (totalsize);
}

size_t		ft_converter(t_type type, va_list list)
{
	size_t	i;
	t_pconv	conv[10];
	conv = {
		{'d', ft_conv_signed},
		{'i', ft_conv_signed},
		{'o', ft_conv_unsigned},
		{'u', ft_conv_unsigned},
		{'x', ft_conv_unsigned},
		{'s', ft_conv_char},
		{'S', ft_conv_char},
		{'c', ft_conv_char},
		{'C', ft_conv_char},
		{'p', ft_conv_ptr}
	};

	i = 0;
	while (i < 11)
	{
		if (type.format == conv[i].letter)
			return (conv[i].ft_conv(type, list));
		i++;
	}
	return (0);
}

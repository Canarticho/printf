/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 07:08:26 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/18 05:57:50 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_pconv	g_conv[10] =
{
	{'d', ft_conv_signed},
	{'i', ft_conv_signed},
	{'o', ft_conv_unsigned},
	{'u', ft_conv_unsigned},
	{'x', ft_conv_unsigned},
	{'X', ft_conv_unsigned},
	{'s', ft_conv_char},
	{'c', ft_conv_char},
	{'p', ft_conv_ptr},
	{'%', ft_doublep}
};

static void	ft_padflags(char **s, t_type *type)
{
	int		tmp;

	tmp = 0;
	type->padflags = 0;
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

	type->pp = 0;
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
		type->pp = 1;
	}
}

static void	ft_mod(char **s, t_type *type)
{
	type->mod = 3;
	while (ft_strchr("hlzj", **s) && type->mod < 6 && type->mod > 0)
	{
		if (ft_strchr("hl", **s))
			type->mod = ((**s) == 'l') ? (type->mod + 1) : (type->mod - 1);
		if (**s == 'z')
			type->mod = 6;
		if (**s == 'j')
			type->mod = 7;
		(*s)++;
	}
}

size_t		ft_getarg(char **s, va_list args)
{
	t_type	type;
	size_t	totalsize;

	totalsize = 0;
	type.format = 0;
	(*s)++;
	if (!**s)
		return (0);
	ft_padflags(s, &type);
	ft_prec(s, &type);
	ft_mod(s, &type);
	if (**s && ft_strchr("DOUXdiouxSsCcp%", **s))
	{
		type.format = **s;
		if (**s && ft_strchr("DOUSC", **s))
		{
			type.mod = 4;
			type.format += 32;
		}
		if (type.format)
			totalsize += ft_converter(type, args);
		(*s)++;
	}
	return (totalsize);
}

size_t		ft_converter(t_type type, va_list list)
{
	size_t			i;

	type.sign.ll = 0;
	type.unsign.ll = 0;
	if (type.mod > 5)
		return (ft_convsp(type, list));
	i = -1;
	while (++i < 12)
		if (type.format == g_conv[i].letter)
			return (g_conv[i].ft_conv(type, list));
	return (0);
}

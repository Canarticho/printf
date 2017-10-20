/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:45:42 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/20 14:48:50 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t			ft_set_min_range_chars(t_type type, size_t size)
{
	if (type.padflags & 2)
		ft_sendbuff('0', size);
	else
		ft_sendbuff(' ', size);
	return (size);
}

size_t			ft_paddingcharsnp(t_type type, char *str)
{
	int padsize;

	if (type.min_range > type.size)
	{
		padsize = type.min_range - type.size;
		if (!(type.padflags & 4))
		{
			ft_set_min_range_chars(type, padsize);
			ft_addbuff(str, type.size, 0);
		}
		else
		{
			ft_addbuff(str, type.size, 0);
			ft_set_min_range_chars(type, padsize);
		}
		return (type.min_range);
	}
	ft_addbuff(str, type.size, 0);
	return (type.size);
}

size_t			ft_padding_chars(t_type type, char *str)
{
	int padsize;

	if (!str && !type.min_range)
	{
		ft_addbuff("(null)", 6, 0);
		return (6);
	}
	if (type.format == 'c' || !type.pp || type.prec > type.size)
		return (ft_paddingcharsnp(type, str));
	if ((padsize = type.min_range - type.prec) > 0)
	{
		if (!(type.padflags & 4))
		{
			ft_set_min_range_chars(type, padsize);
			ft_addbuff(str, type.prec, 0);
		}
		else
		{
			ft_addbuff(str, type.prec, 0);
			ft_set_min_range_chars(type, padsize);
		}
		return (type.min_range);
	}
	ft_addbuff(str, type.prec, 0);
	return (type.prec);
}

static size_t	ft_paddingwcharsnp(t_type type, wchar_t *str)
{
	int		padsize;

	if ((padsize = type.min_range - type.size) > 0)
	{
		if (!(type.padflags & 4))
		{
			ft_set_min_range_chars(type, padsize);
			ft_co_wchar(str, -1, type);
		}
		else
		{
			ft_co_wchar(str, -1, type);
			ft_set_min_range_chars(type, padsize);
		}
		return (type.min_range);
	}
			ft_co_wchar(str, -1, type);
	return (type.size);
}

size_t			ft_padding_wchars(t_type type, wchar_t *str)
{
	int		padsize;

	if (!str && !type.min_range)
	{
		ft_addbuff("(null)", 6, 0);
		return (6);
	}
	if (!type.pp || type.prec > type.size || type.format == 'c')
		return (ft_paddingwcharsnp(type, str));
	if ((padsize = type.min_range - type.prec > 0))
	{
		if (!(type.padflags & 4))
		{
			ft_set_number_field(type, 0 - type.size);
			ft_co_wchar(str, type.prec, type);
		}
		else
		{
			ft_co_wchar(str, -1, type);
			ft_set_number_field(type, type.prec - type.size);
		}
		return (type.min_range);
	}
			ft_co_wchar(str, type.prec, type);
	return (type.prec);
}

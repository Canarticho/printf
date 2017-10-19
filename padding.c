/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:45:42 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/19 01:34:59 by chle-van         ###   ########.fr       */
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

static size_t	ft_paddingcharsnp(t_type type, char *str, char state)
{
	int padsize;

	if (type.min_range > type.size)
	{
		padsize = type.min_range - type.size;
		if (!(type.padflags & 4))
		{
			ft_set_min_range_chars(type, padsize);
			ft_addbuff(str, type.size, state);
		}
		else
		{
			ft_addbuff(str, type.size, state);
			ft_set_min_range_chars(type, padsize);
		}
		return (type.min_range);
	}
	ft_addbuff(str, type.size, state);
	return (type.size);
}

size_t			ft_padding_chars(t_type type, char *str, char state)
{
	int padsize;

	if (!str)
	{
		ft_addbuff("(null)", 6, 0);
		return (6);
	}
	if (type.format == 'c' || !type.pp || type.prec > type.size)
		return (ft_paddingcharsnp(type, str, state));
	if ((padsize = type.min_range - type.prec) > 0)
	{
		if (!(type.padflags & 4))
		{
			ft_set_min_range_chars(type, padsize);
			ft_addbuff(str, type.prec, state);
		}
		else
		{
			ft_addbuff(str, type.prec, state);
			ft_set_min_range_chars(type, padsize);
		}
		return (type.min_range);
	}
	ft_addbuff(str, type.prec, state);
	return (type.prec);
}

static size_t	ft_paddingwcharsnp(t_type type, wchar_t *str, char state)
{
	int padsize;

	if ((padsize = type.min_range - type.size) > 0)
	{
		if (!(type.padflags & 4))
		{
			ft_set_min_range_chars(type, padsize);
			ft_addbuffw(str, type.size, state);
		}
		else
		{
			ft_addbuffw(str, type.size, state);
			ft_set_min_range_chars(type, padsize);
		}
		return (type.min_range);
	}
	ft_addbuffw(str, type.size, state);
	return (type.size);
}

size_t			ft_padding_wchars(t_type type, wchar_t *str, char state)
{
	int padsize;

	if (!type.pp || type.prec > type.size)
		return (ft_paddingwcharsnp(type, str, state));
	if (type.min_range > type.prec)
	{
		padsize = type.min_range - type.prec;
		if (!(type.padflags & 4))
		{
			ft_set_number_field(type, type.prec - type.size);
			ft_addbuffw(str, type.prec, state);
		}
		else
		{
			ft_addbuffw(str, type.prec, state);
			ft_set_number_field(type, type.prec - type.size);
		}
		return (type.min_range);
	}
	ft_addbuffw(str, type.prec, state);
	return (type.prec);
}

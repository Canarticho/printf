/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 13:45:42 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/08 16:09:52 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	ft_paddingcharsnp(t_type type, wchar_t *str, char state)
{
	size_t padsize;

	if (type.min_range > type.size)
	{
		padsize = type.min_range - type.size;
		if (!(type.padflags & 4))
		{
			ft_sendbuff(' ', padsize);
			ft_addbuff(str, type.size, state);
		}
		else
		{
			ft_addbuff(str, type.size, state);
			ft_sendbuff(' ', padsize);
		}
		return (type.min_range);
	}
	ft_addbuff(str, type.size, state);
	return (type.size);
}

size_t			ft_padding_chars(t_type type, wchar_t *str, char state)
{
	size_t padsize;

	if (!type.pp || type.prec > type.size)
		return (ft_paddingcharsnp(type, str, state));
	if (type.min_range > type.prec)
	{
		padsize = type.min_range - type.prec;
		if (!(type.padflags & 4))
		{
			ft_sendbuff(' ', padsize);
			ft_addbuff(str, type.prec, state);
		}
		else
		{
			ft_addbuff(str, type.prec, state);
			ft_sendbuff(' ', padsize);
		}
		return (type.min_range);
	}
	ft_addbuff(str, type.prec, state);
	return (type.prec);
}

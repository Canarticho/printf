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

size_t	ft_padding_chars(t_type type, wchar_t *str, char state)
{
	size_t padsize;

	padsize = 0;
	if (type.min_range > type.prec || type.min_range > type.size)
	{
		if (type.size > type.prec && type.prec != 0)
			padsize = type.min_range - type.prec;
		else
			padsize = type.min_range - type.size;
		if (!(type.padflags & 4))
		{
			ft_sendbuff(' ', padsize);
			if (type.prec)
				ft_addbuff(str, type.prec, state);
			else
				ft_addbuff(str, type.size, state);
		}
		else
		{
			if (type.prec)
				ft_addbuff(str, type.prec, state);
			else
				ft_addbuff(str, type.size, state);
			ft_sendbuff(' ', padsize);
		}
		return (type.prec + padsize);
	}
	else if (type.prec)
		ft_addbuff(str, type.prec, state);
	else
		ft_addbuff(str, type.size, state);
	return ((type.prec == 0) ? (type.size) : (type.prec));
}

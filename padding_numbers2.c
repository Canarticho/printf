/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_numbers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 01:56:05 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/18 05:19:43 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_set_number_field(t_type type, int neg)
{
	int padsize;
	int soust;
	int size;

	soust = (type.prec > type.size) ? (type.prec) : (type.size);
	soust = soust + neg;
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
		size = padsize;
	}
	return (size);
}

size_t	ft_set_number_prec(t_type type)
{
	int size;
	int padsize;

	size = 0;
	padsize = type.prec - type.size;
	if (padsize >= 0 && ((type.mod == 1 && type.sign.c < 0) ||
				(type.mod == 2 && type.sign.s < 0) ||
			(type.mod == 3 && type.sign.i < 0) ||
			(type.mod == 4 && type.sign.l < 0)
			|| (type.mod == 5 && type.sign.ll < 0)))
	{
		ft_sendbuff('0', padsize + 1);
		size += padsize + 1;
	}
	else if (padsize > 0)
	{
		ft_sendbuff('0', padsize);
		size += padsize;
	}
	return (size);
}

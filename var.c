/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 14:41:42 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/04 17:04:29 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_plltoa(t_type type)
{
	static char	res[16 * 8 + 2];

	ft_bzero(res, 16 * 8 + 2);
	if (ft_strchr("ouxX", type.format))
		return (ft_ulltoa(type.sign.ll, res, 10));
	else
		ft_lltoa(type.sign.ll, res, 10);
	return (res);
}

char		*ft_pltoa(t_type type)
{
	static char	res[8 * 8 + 2];

	ft_bzero(res, 8 * 8 + 2);
	if (ft_strchr("ouxX", type.format))
		return (ft_ultoa(type.sign.l, res, 10));
	else
		ft_ltoa(type.sign.l, res, 10);
	return (res);
}

char		*ft_pitoa(t_type type)
{
	static char	res[4 * 8 + 2];

	ft_bzero(res, 4 * 8 + 2);
	if (ft_strchr("ouxX", type.format))
		return (ft_uitoa(type.sign.i, res, 10));
	else
		ft_itoa(type.sign.i, res, 10);
	return (res);
}

char		*ft_pstoa(t_type type)
{
	static char	res[2 * 8 + 2];

	ft_bzero(res, 2 * 8 + 2);
	if (ft_strchr("ouxX", type.format))
		return (ft_ustoa(type.sign.s, res, 10));
	else
		ft_stoa(type.sign.s, res, 10);
	return (res);
}

char		*ft_pctoa(t_type type)
{
	static char	res[1 * 8 + 2];

	ft_bzero(res, 1 * 8 + 2);
	if (ft_strchr("ouxX", type.format))
		return (ft_uctoa(type.sign.c, res, 10));
	else
		ft_ctoa(type.sign.c, res, 10);
	return (res);
}

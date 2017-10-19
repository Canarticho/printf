/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 03:04:47 by chle-van          #+#    #+#             */
/*   Updated: 2016/12/01 00:04:29 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	ft_value(char c, int base)
{
	char	b[16];
	int		i;

	i = 0;
	ft_strcpy(b, "0123456789abcdef");
	while (i < base && b[i] != c)
	{
		i++;
	}
	return (i);
}

int			ft_atoi_base(const char *str, int base)
{
	int				pos;
	unsigned int	res;

	res = 0;
	pos = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		pos = (*(str++) == '-') ? (-1) : (1);
	if (*str == '+' || *str == '-')
		return (0);
	while (ft_strchr("0123456789abcdef", *str) && *str)
		res = res * base + ft_value(*(str++), base);
	return (pos * res);
}

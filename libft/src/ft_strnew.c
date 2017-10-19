/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 02:49:29 by chle-van          #+#    #+#             */
/*   Updated: 2017/02/12 06:03:31 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!(tmp = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= size)
		tmp[i++] = '\0';
	return (tmp);
}

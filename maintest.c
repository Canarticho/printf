/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 14:14:49 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/18 07:02:25 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main(void)
{
	int i = 0;

//	i = ft_printf("@moulitest: %#.o %#.0o", 0, 0);
//	ft_putchar('\n');
//	ft_putnbr(i);
//	ft_putchar('\n');
	i = ft_printf("%p", &i);
	ft_putchar('\n');
	ft_putnbr(i);
	ft_putchar('\n');
	i = printf("%p", &i);
	ft_putchar('\n');
	ft_putnbr(i);
	ft_putchar('\n');
	return (0);
}

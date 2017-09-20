/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 14:14:49 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/15 14:38:51 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int main(void)
{
	int i = 0;

	i = ft_printf("%5%", -1);
	ft_putchar('\n');
	ft_putnbr(i);
	ft_putchar('\n');
	i = ft_printf("%-5%", 4242);
	ft_putchar('\n');
	ft_putnbr(i);
	ft_putchar('\n');
	i = ft_printf("%   %", 0, 0);
	ft_putchar('\n');
	ft_putnbr(i);
	ft_putchar('\n');
	return (0);
}
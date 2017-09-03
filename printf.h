/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 17:18:32 by chle-van          #+#    #+#             */
/*   Updated: 2017/09/03 15:32:31 by chle-van         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include "libft.h"
# define BUFF_SIZE 2000
# define FLUSH 1
# define FREE 2

typedef	struct				s_type
{
	union					u_sign
	{
		char				c;
		short				s;
		int					i;
		long				l;
		long long			ll;
	}						sign;

	union					u_unsign
	{
		unsigned char		c;
		unsigned short		s;
		unsigned int		i;
		unsigned long		l;
		unsigned long long	ll;
	}						unsign;

	size_t					size;
	size_t					min_range;
	size_t					prec;
	int						mod;
	char					padflags;
	char					format;
}							t_type;

typedef size_t				(t_conv)(t_type type, va_list list);
typedef	struct				s_pconv
{
	char					letter;
	t_conv					*ft_conv;
}							t_pconv;

int							ft_printf(const char *s, ...);
size_t						ft_conv_signed(t_type type, va_list list);
size_t						ft_conv_unsigned(t_type type, va_list list);
int							ft_padding_number(wchar_t *str, t_type type);
size_t						ft_conv_ptr(t_type type, va_list arg);
size_t						ft_conv_char(t_type type, va_list arg);
size_t						ft_padding_chars(t_type type, wchar_t *str, char s);
void						ft_addbuff(void *src, size_t size, char flag);
void						ft_sendbuff(char c, int size);
size_t						ft_getarg(char **src, va_list args);
size_t						ft_converter(t_type type, va_list list);
size_t						ft_set_number_field(t_type type);
#endif

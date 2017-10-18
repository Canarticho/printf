/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chle-van <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 17:18:32 by chle-van          #+#    #+#             */
/*   Updated: 2017/10/18 03:53:01 by chle-van         ###   ########.fr       */
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
		ssize_t				sst;
		long				l;
		long long			ll;
		intmax_t			im;
	}						sign;

	union					u_unsign
	{
		unsigned char		c;
		unsigned short		s;
		unsigned int		i;
		size_t				st;
		unsigned long		l;
		unsigned long long	ll;
		uintmax_t			um;
	}						unsign;

	size_t					size;
	size_t					min_range;
	size_t					prec;
	char					pp;
	int						mod;
	char					padflags;
	char					format;
}							t_type;

typedef char				*(t_var)(t_type type, int base);
typedef	struct				s_pvar
{
	int						mod;
	t_var					*ft_var;
}							t_pvar;

typedef size_t				(t_conv)(t_type type, va_list list);
typedef	struct				s_pconv
{
	char					letter;
	t_conv					*ft_conv;
}							t_pconv;

int							ft_printf(const char *s, ...);
size_t						ft_set_number_prec(t_type type);
size_t						ft_conv_signed(t_type type, va_list list);
size_t						ft_conv_unsigned(t_type type, va_list list);
size_t						ft_padding_number(char *str, t_type type);
size_t						ft_conv_ptr(t_type type, va_list arg);
size_t						ft_conv_char(t_type type, va_list arg);
void						ft_addbuff(void *src, size_t size, char flag);
size_t						ft_padding_wchars(t_type type, wchar_t *ws, char s);
size_t						ft_padding_chars(t_type type, char *str, char s);
void						ft_sendbuff(char c, int size);
void						ft_addbuffw(void *src, size_t size, char flag);
void						ft_sendbuffw(char c, int size);
size_t						ft_getarg(char **src, va_list args);
size_t						ft_converter(t_type type, va_list list);
size_t						ft_convsp(t_type type, va_list list);
size_t						ft_set_number_field(t_type type, int n);
size_t						ft_doublep(t_type type, va_list list);
char						*ft_plltoa(t_type type, int base);
char						*ft_pltoa(t_type type, int base);
char						*ft_pitoa(t_type type, int base);
char						*ft_pstoa(t_type type, int base);
char						*ft_pctoa(t_type type, int base);
#endif

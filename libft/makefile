# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chle-van <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 01:43:30 by chle-van          #+#    #+#              #
#    Updated: 2017/09/04 16:51:44 by chle-van         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

FLAGS=-Wall -Wextra -Werror

FILES=ft_atoi.c\
ft_atoi_base.c\
ft_bzero.c\
ft_countn.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_isspace.c\
ft_lltoa.c\
ft_ltoa.c\
ft_itoa.c\
ft_stoa.c\
ft_ctoa.c\
ft_ulltoa.c\
ft_ultoa.c\
ft_uitoa.c\
ft_ustoa.c\
ft_uctoa.c\
ft_lstadd.c\
ft_lstdel.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstmap.c\
ft_lstnew.c\
ft_memalloc.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memdel.c\
ft_memmove.c\
ft_memset.c\
ft_putchar.c\
ft_putchar_fd.c\
ft_putendl.c\
ft_putendl_fd.c\
ft_putnbr.c\
ft_putnbr_fd.c\
ft_putstr.c\
ft_putstr_fd.c\
ft_putwchar.c\
ft_putwcs.c\
ft_stpcpy.c\
ft_sqrt.c\
ft_strcat.c\
ft_strchr.c\
ft_strclr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strequ.c\
ft_striter.c\
ft_striteri.c\
ft_strjoin.c\
ft_strjoindel.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strmap.c\
ft_strmapi.c\
ft_strncat.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strndup.c\
ft_strnequ.c\
ft_strnew.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strrev.c\
ft_strsplit.c\
ft_strstr.c\
ft_strsub.c\
ft_strtrim.c\
ft_tolower.c\
ft_toupper.c\
ft_wcscpy.c\
ft_wcslen.c\
ft_wcsnew.c\
ft_strtowcs.c\
ft_strtowcsd.c\
ft_wcschr.c\
ft_wcsrev.c\
ft_wcsset.c\
ft_abs.c\
ft_wcsdel.c\
ft_wcstoupper.c

OBJ_NAME=$(FILES:.c=.o)

SRC_DIR=src/

SRC=$(addprefix $(SRC_DIR), $(FILES))

INCLUDES_DIR=includes/

NAME=libft.a

all:$(NAME)

$(NAME):$(OBJ_NAME)
	ar rc $@ $(OBJ_NAME)

$(OBJ_NAME)%.o: $(SRC)
	$(CC) $(FLAGS) -c $^ -I $(INCLUDES_DIR)

re:fclean all

clean:
	rm -rf *.o

fclean:clean
	rm  -rf $(NAME)

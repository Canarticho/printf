LIB_PATH=./libft/
CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC=chars.c\
	buffer.c\
	inp.c\
	numeric.c\
	padding.c\
	padding_numbers.c\
	padding_numbers2.c\
	wchar.c\
	printf.c\
	var.c

OBJ=$(SRC:.c=.o)
	NAME=libftprintf.a
	LIB_NAME=libft.a
	LIB_FILE=$(LIB_PATH)$(LIB_NAME)
	INCLUDES_DIR=$(LIB_PATH)includes/
	PRLIB=printf.a

all:$(NAME)

$(LIB_FILE): 
	cd $(LIB_PATH) && $(MAKE)

$(NAME):$(LIB_FILE) $(PRLIB)
	libtool -static -o $@ $^

$(PRLIB):$(OBJ)
	ar rc $@ $^

$(OBJ)%.o: $(SRC)
	$(CC) $(CFLAGS) -c $^ -I $(INCLUDES_DIR)

re:fclean all

clean:
	rm -rf $(OBJ)
	rm -rf $(LIB_FILE) $(LIB) $(PRLIB)
	cd $(LIB_PATH) && $(MAKE) fclean

fclean:clean
	rm -rf $(NAME)

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 21:01:10 by oposhiva          #+#    #+#              #
#    Updated: 2019/04/02 21:01:11 by oposhiva         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

CC = gcc

LIBFT = printflibft/libftprintf.a

SRC =	main.c\
		source/malloc.c\
		source/realloc.c\
		source/free.c\

OBJ = $(SRC:.c=.o)

HEADERS = headers/malloc.h printflibft/get_next_line.h printflibft/ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT):
	make -C printflibft/

libft_clean:
	make -C printflibft/ clean

libft_fclean:
	make -C printflibft/ fclean

clean: libft_clean
	rm -f $(OBJ) headers/malloc.h.gch get_next_line.h.gch *~

fclean: clean libft_fclean
	rm -f $(NAME)

re: fclean all
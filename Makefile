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

LIBFT = libft/libft.a

SRC =	main.c\
		source/malloc.c\
		source/realloc.c\
		source/free.c\
		source/zone_handler.c\
		source/cell_handler.c\
		source/large_cell.c\
		source/new_zone.c\
		source/getter.c\
		source/cell_del.c\
		source/show_alloc_mem.c\
		source/calloc.c\

OBJ = $(SRC:.c=.o)

HEADERS = headers/malloc.h libft/libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): %.o: %.c
	$(CC) -c  $< -o $@

$(LIBFT):
	make -C libft/

libft_clean:
	make -C libft/ clean

libft_fclean:
	make -C libft/ fclean

clean: libft_clean
	rm -f $(OBJ) headers/malloc.h.gch get_next_line.h.gch *~

fclean: clean libft_fclean
	rm -f $(NAME)

re: fclean all
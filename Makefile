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
LINK = libft_malloc.so

CC = gcc

LIBFT = libft/libft.a

SRC =	source/malloc.c\
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

FLAGS = -Wall -Wextra -Werror -shared

all: $(NAME) done

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(FLAGS) $(LIBFT)
	ln -s $(NAME) $(LINK)

$(LIBFT):
	make -C libft/
	@echo "\033[;35m[ Libft is ready ]\033[33;0m"

libft_clean:
	make -C libft/ clean

libft_fclean:
	make -C libft/ fclean

clean: libft_clean
	rm -f $(OBJ) headers/malloc.h.gch get_next_line.h.gch *~
	@echo "\033[;33m[ It's clean ]\033[33;0m"

fclean: clean libft_fclean
	rm -f $(NAME)
	rm -f $(LINK)
	@echo "\033[;31m[ Deleted ]\033[33;0m"

re: fclean all

done:
	@echo "\033[;32m[ Well done ]\033[33;0m"
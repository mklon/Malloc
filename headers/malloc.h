/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:10:14 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/02 20:10:14 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

#include <stdio.h>

# include <stdlib.h>
# include <sys/mman.h>
# include "../printflibft/get_next_line.h"
# include "../printflibft/ft_printf.h"
# include "../printflibft/libft/libft.h"

# define TINY_ZONE 512
# define SMALL_ZONE TINY_ZONE * 16

# define CELLS_IN_ZONE 100

# define TINY	1
# define SMALL	2
# define LARGE	3

# define CELL_SIZE (sizeof(t_cell))

typedef	enum	e_bool {
	TRUE,
	FALSE
}				t_bool;

typedef struct	s_allmem {
	void	*tiny_zone_begin;
	void	*small_zone_begin;
	void	*large_zone_begin;
}				t_allmem;

typedef struct	s_cell {
	void		*cell_begin;
	void		*next_cell;
	void		*mem_area;
	char 		type;
	size_t		cell_num;
	size_t		size;
	t_bool		is_occupied;
}				t_cell;

t_allmem		*g_init;

/*
**	malloc.c
*/

void			*malloc(size_t size);

/*
**	realloc.c
*/

void			*realloc(void *ptr, size_t size);

/*
**	free.h
*/

void			free(void *ptr);

/*
**	zone_handler.c
*/

void	*allocate_mem(size_t mem_size);
size_t	calculate_memory(size_t size, size_t page_amount, size_t allocations);
size_t	get_memory_size(size_t size, char type);
void	*assign_zone(void *ptr, size_t size, char type);
void	*assign_mem(size_t size, t_allmem *mem);

//size_t	get_memory_size(size_t zone_size, char type);

/*
**	cell_handler.c
*/

void	*init_first_cell(void *zone_begin, size_t cell_size, char type);
t_cell	*get_free_cell(t_cell *first_cell, size_t size);

#endif

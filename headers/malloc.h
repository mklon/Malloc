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

# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include "../libft/libft.h"

# define TINY_ZONE 1024
# define SMALL_ZONE TINY_ZONE * 16

# define CELLS_IN_ZONE 175

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
	char		type;
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
**	calloc.c
*/

void			*calloc(size_t num, size_t size);

/*
**	zone_handler.c
*/

void			*allocate_mem(size_t mem_size);
size_t			calculate_memory(size_t size, size_t page_amount,
									size_t allocations);
size_t			get_memory_size(size_t size, char type);
void			*assign_zone(void *ptr, size_t size, char type);
void			*assign_mem(size_t size, t_allmem *mem);

/*
**	cell_handler.c
*/

void			*init_first_cell(void *zone_begin, size_t cell_size, char type);
t_cell			*init_next_cell(void *ptr, t_cell *pre_cell);
t_cell			*get_free_cell(t_cell *first_cell, size_t size);

/*
**	large_cell.c
*/

t_cell			*allocate_large_zone(t_cell *first_cell, size_t size);

/*
**	new_zone.c
*/

t_cell			*init_new_zone_cell(void *new_zone_begin, t_cell *pre_zone);
t_cell			*allocate_new_zone(t_cell *last_cell, size_t size);

/*
**	getter.c
*/

char			get_size_type(size_t size);
size_t			get_max_size(size_t size);
void			ft_put_addr(int addr);

/*
**	cell_del.c
*/

t_cell			*find_in_zone(t_cell *first_cell, void *mem);
t_cell			*find_cell(void *ptr);
void			free_large_cell(t_cell *cell);

/*
**	show_alloc_mem.c
*/

void			display_zone(void *ptr);
void			show_alloc_mem(void);

#endif

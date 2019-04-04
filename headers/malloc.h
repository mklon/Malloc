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
# include <sys/mman.h>
# include "../printflibft/get_next_line.h"
# include "../printflibft/ft_printf.h"
# include "../printflibft/libft/libft.h"

# define TINY_ZONE 1024
# define SMALL_ZONE TINY_ZONE * 16

# define ZONE_ALLOCATIONS 100

# define TINY	1
# define SMALL	2
# define LARGE	3

# define ALLOCATION_SIZE (sizeof(t_cell))

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
	void		*cell_type;
	void		*cell_size;
	void		*zone_begin;
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

size_t	get_memory_size(size_t zone_size, char type);
void	*assign_mem(size_t size, t_allmem *mem);

#endif

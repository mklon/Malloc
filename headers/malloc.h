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
# include "../printflibft/get_next_line.h"
# include "../printflibft/ft_printf.h"
# include "../printflibft/libft/libft.h"

# define TINY_ZONE 1024
# define SMALL_ZONE TINY_ZONE * 16

# define ZONE_ALLOCATIONS 100


/*
**	malloc.c
*/

void	*malloc(size_t size);

/*
**	realloc.c
*/

void	*realloc(void *ptr, size_t size);

/*
**	free.h
*/

void	free(void *ptr);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:04:34 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/02 20:04:35 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc.h"

void	*malloc(size_t size)
{
	static t_allmem	mem;
	t_cell			*first_cell;
	t_cell 			*cell;

	if (!g_init)
		g_init = &mem;
	first_cell = assign_mem(size, &mem);
	if (first_cell == NULL)
		return (NULL);

	cell = get_free_cell(first_cell, size);

	return (cell->mem_area);
}

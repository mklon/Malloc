/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_cell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:40:11 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/07 11:40:12 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc.h"

t_cell	*init_large_zone(void *ptr, t_cell *pre_cell, size_t size)
{
	t_cell	*cell;

	cell = (t_cell*)ptr;
	cell->cell_begin = cell;
	cell->next_cell = NULL;
	cell->mem_area = cell->cell_begin + CELL_SIZE;
	cell->cell_num = pre_cell->cell_num + 1;
	cell->is_occupied = TRUE;
	cell->type = LARGE;
	cell->size = size;

	return (cell->cell_begin);
}

t_cell	*allocate_large_zone(t_cell *first_cell, size_t size)
{
	t_cell	*pre_cell;
	t_cell	*new_cell;
	t_cell	*free_cell;

	free_cell = first_cell;

	while (free_cell != NULL)
	{
		pre_cell = free_cell;
		free_cell = free_cell->next_cell;
	}
	new_cell = assign_zone(new_cell, size, LARGE);
	if (new_cell == NULL)
		return (NULL);
	pre_cell->next_cell = init_large_zone(new_cell, pre_cell, size);
	return (pre_cell->next_cell);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:25:23 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/06 11:25:24 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc.h"

void	*init_first_cell(void *zone_begin, size_t cell_size, char type)
{
	t_cell	*cell;

	if (zone_begin == NULL)
		return NULL;

	cell = (t_cell*)zone_begin;
	cell->cell_begin = zone_begin;
	cell->next_cell = NULL;
	cell->mem_area = cell->cell_begin + CELL_SIZE;
	cell->cell_num = 1;
	cell->is_occupied = FALSE;
	cell->size = cell_size;
	cell->type = type;

	return (cell->cell_begin);
}

t_cell	*init_next_cell(void *ptr, t_cell* pre_cell)
{
	t_cell	*cell;

	cell = (t_cell*)(ptr + pre_cell->size + CELL_SIZE);
	cell->cell_begin = cell;
	cell->next_cell = NULL;
	cell->mem_area = cell->cell_begin + CELL_SIZE;
	cell->cell_num = pre_cell->cell_num + 1;
	cell->is_occupied = TRUE;
	cell->type = pre_cell->type;
	cell->size = pre_cell->size;

	return (cell->cell_begin);
}

t_cell	*get_free_cell(t_cell *first_cell, size_t size)
{
	t_cell	*pre_cell;
	t_cell	*free_cell;

	pre_cell = NULL;
	free_cell = first_cell;
	if (free_cell->type == LARGE)
		return (allocate_large_zone(free_cell, size));
	while (free_cell != NULL)
	{
		if (free_cell->cell_num % CELLS_IN_ZONE == 0 && free_cell->next_cell == NULL)
			return (allocate_new_zone(free_cell, size));
		if (free_cell->is_occupied == FALSE)
		{
			free_cell->is_occupied = TRUE;
			return (free_cell->cell_begin);
		}
		pre_cell = free_cell;
		free_cell = free_cell->next_cell;
	}
	pre_cell->next_cell = init_next_cell(pre_cell, pre_cell)->cell_begin;
	return (pre_cell->next_cell);
}

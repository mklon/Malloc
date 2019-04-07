/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_zone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:19:55 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/07 12:19:55 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc.h"

t_cell	*init_new_zone_cell(void *new_zone_begin, t_cell *pre_zone)
{
	t_cell	*cell;

	cell = (t_cell*)new_zone_begin;
	cell->cell_begin = cell;
	cell->next_cell = NULL;
	cell->mem_area = cell->cell_begin + CELL_SIZE;
	cell->cell_num = pre_zone->cell_num + 1;
	cell->is_occupied = TRUE;
	cell->type = pre_zone->type;
	cell->size = pre_zone->size;

	return (cell->cell_begin);
}

t_cell	*allocate_new_zone(t_cell *last_cell, size_t size)
{
	t_cell	*new_zone;

	new_zone = assign_zone(new_zone, get_max_size(size), get_size_type(size));
	if (new_zone == NULL)
		return (NULL);
	last_cell->next_cell = init_new_zone_cell(new_zone, last_cell);
	return (last_cell->next_cell);
}
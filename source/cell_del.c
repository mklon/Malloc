/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:57:57 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/07 15:57:58 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc.h"

t_cell	*find_in_zone(t_cell *first_cell, void *mem)
{
	while (first_cell != NULL)
	{
		if (first_cell->mem_area == mem)
			return (first_cell->cell_begin);
		first_cell = first_cell->next_cell;
	}
	return (NULL);
}

t_cell	*find_cell(void *ptr)
{
	t_cell	*cell;

	if (ptr == NULL)
		return (NULL);
	cell = find_in_zone(g_init->tiny_zone_begin, ptr);
	if (cell == NULL)
	{
		cell = find_in_zone(g_init->small_zone_begin, ptr);
		if (cell == NULL)
		{
			cell = find_in_zone(g_init->large_zone_begin, ptr);
			if (cell == NULL)
				return (NULL);
		}
	}
	return (cell->cell_begin);
}

void	free_cell(t_cell *cell)
{
	munmap(cell->cell_begin, cell->size + CELL_SIZE);
}

void	free_large_cell(t_cell *cell)
{
	t_cell	*pre_cell;
	t_cell	*last_cell;

	pre_cell = NULL;
	last_cell = (t_cell*)g_init->large_zone_begin;
	while (last_cell != NULL)
	{
		if (last_cell == cell->cell_begin)
			break ;
		pre_cell = last_cell;
		last_cell = last_cell->next_cell;
	}
	if (pre_cell == NULL)
		g_init->large_zone_begin = NULL;
	else
		pre_cell->next_cell = cell->next_cell;
	free_cell(cell->cell_begin);
}

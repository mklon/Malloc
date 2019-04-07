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

t_cell	*find_cell(void *ptr)
{
	t_cell	*cell;

	if (ptr == NULL)
		return (NULL);
	cell = (t_cell*)(ptr - CELL_SIZE);
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
	while(last_cell != NULL)
	{
		if (last_cell == cell->cell_begin)
			break;
		pre_cell = last_cell;
		last_cell = last_cell->next_cell;
	}
	if (pre_cell == NULL)
		g_init->large_zone_begin = NULL;
	else
		pre_cell->next_cell = cell->next_cell;
	free_cell(cell->cell_begin);
}
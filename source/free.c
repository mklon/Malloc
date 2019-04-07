/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:45:16 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/02 20:45:16 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc.h"

void	free(void *ptr)
{
	t_cell	*cell;

	cell = find_cell(ptr);
	if (cell == NULL)
		return;
	if (cell->type == LARGE)
	{
		free_large_cell(cell);
		return;
	}
	cell->is_occupied = FALSE;
	//CHECK FOR ZONE DELETION
}

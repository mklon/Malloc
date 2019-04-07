/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:45:38 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/02 20:45:39 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc.h"

void	*realloc(void *ptr, size_t size)
{
	void	*new_ptr;
	t_cell	*cell;

	cell = find_cell(ptr);
	if (cell == NULL)
		return (NULL);
	new_ptr = NULL;
	if (size != 0)
		new_ptr = malloc(size);
	ft_strncpy(new_ptr, cell->mem_area, size);
	free(cell->mem_area);
	return (new_ptr);
}

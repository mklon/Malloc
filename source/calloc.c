/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:07:33 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/07 20:07:33 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc.h"

void	*calloc(size_t num, size_t size)
{
	t_cell	*cell;

	cell = malloc(size * num);
	if (cell == NULL)
		return (NULL);
	return (cell->mem_area);
}
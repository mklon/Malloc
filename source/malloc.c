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
	t_cell		*zone;
	void 		*ptr;

	if (!g_init)
		g_init = &mem;
	zone = assign_mem(size, &mem);
	if (zone == NULL)
		return (NULL);

	return (ptr);
}

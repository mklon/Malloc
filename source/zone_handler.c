/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:40:00 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/03 19:40:01 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc.h"

size_t	calculate_memory(size_t size, size_t page_amount, size_t allocations){
	size_t	i;
	size_t	page;

	i = 0;
	page = (size_t)getpagesize();
	if (!allocations || !page)
		return (page_amount);
	while (1)
	{
		i = (page * page_amount++) / size;
		if (ZONE_ALLOCATIONS < i)
			return (page_amount * page);
	}
}

size_t	get_memory_size(char zone_type, size_t size)
{
	if (zone_type == TINY || zone_type == SMALL)
		return (calculate_memory(size, 0, 0));
	else
		return (ALLOCATION_SIZE + size);
}

t_zone	*assign_zone(size_t size)
{
	t_zone	*zone;
	size_t	*memsize;

	if (size <= TINY_ZONE)
		memsize = get_memory_size(TINY, TINY_ZONE);
	else if (size <= SMALL_ZONE)
		memsize = get_memory_size(SMALL, SMALL_ZONE);
	else
		memsize = get_memory_size(LARGE, size);


	mmap(0, memsize, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	//INIT

	return (zone);
}

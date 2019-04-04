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

size_t	get_memory_size(size_t size, char type)
{
	if (type == TINY || type == SMALL)
		return (calculate_memory(size, 0, ALLOCATION_SIZE + size));
	else
		return (ALLOCATION_SIZE + size);
}

void	*assign_zone(void *ptr, size_t size, char type)
{
	size_t	zone_size;

	if (ptr)
		return (ptr);
	zone_size = get_memory_size(size, type);


	ft_printf("32");
	return (NULL);

}

void	*assign_mem(size_t size, t_allmem *mem)
{
	if (size <= TINY_ZONE)
		return ((t_cell*)assign_zone(mem->tiny_zone_begin, size, LARGE));
	else if (size <= SMALL_ZONE)
		return (assign_zone(mem->small_zone_begin, size, SMALL));
	else
		return (assign_zone(mem->large_zone_begin, size, LARGE));
}

/*
	zone = mmap(0, memsize, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (zone == MAP_FAILED)
		return (NULL);
*/

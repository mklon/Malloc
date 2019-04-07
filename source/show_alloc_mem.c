/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:37:45 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/07 18:37:46 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc.h"

void	display_zone(void *ptr)
{
	t_cell *first_cell;


	if (ptr == NULL)
	{
		ft_putstr("Zone is empty!\n");
		return;
	}
	first_cell = (t_cell*)ptr;
	while (first_cell != NULL)
	{
		ft_put_addr((int)first_cell->cell_begin);
		ft_putstr(" - ");
		ft_put_addr((int)(first_cell->cell_begin + first_cell->size));
		ft_putstr(" : ");
		ft_putnbr(first_cell->size);
		ft_putstr(" bytes\n");
		first_cell = first_cell->next_cell;
	}
}

void	show_alloc_mem()
{
	if (g_init == NULL)
	{
		ft_putstr("All zones are empty!\n");
		return;
	}

	ft_putstr("TINY ZONE : ");
	ft_put_addr((int)g_init->tiny_zone_begin);
	ft_putstr("\n");
	display_zone(g_init->tiny_zone_begin);
	ft_putstr("\nSMALL ZONE : ");
	ft_put_addr((int)g_init->small_zone_begin);
	ft_putstr("\n");
	display_zone(g_init->small_zone_begin);
	ft_putstr("\nLARGE ZONE : ");
	ft_put_addr((int)g_init->large_zone_begin);
	ft_putstr("\n");
	display_zone(g_init->large_zone_begin);
}
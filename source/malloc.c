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
	t_zone	*zone;

	zone = (t_zone*)g_init;
	if (!zone)
	{
		zone = assign_zone(size);
	}
	return (NULL);
	return (NULL);
}

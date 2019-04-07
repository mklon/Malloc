/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <oposhiva@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:43:40 by oposhiva          #+#    #+#             */
/*   Updated: 2019/04/07 12:43:40 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/malloc.h"

char	get_size_type(size_t size)
{
	if (size <= TINY_ZONE)
		return (TINY);
	else if (size <= SMALL_ZONE)
		return (SMALL);
	else
		return (LARGE);
}

size_t	get_max_size(size_t size)
{
	if (size <= TINY_ZONE)
		return (TINY_ZONE);
	else if (size <= SMALL_ZONE)
		return (SMALL_ZONE);
	else
		return (size);
}
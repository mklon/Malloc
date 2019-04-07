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

void *realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	ptr = find_cell(ptr);
	if (ptr == NULL)
		return (NULL);
	new_ptr = NULL;
	if (size != 0)
		new_ptr = malloc(size);
	if (ptr != NULL) {
		ft_strncpy(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
}

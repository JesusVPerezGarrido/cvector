/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/21 11:35:57 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_int.h"

int vctrnew(t_vector *vector, size_t capacity, size_t element_size, void (*del)(void *))
{
	if (!vector || element_size == 0)
		return (ERROR);
	vector->element_size = element_size;
	vector->capacity = capacity;
	vector->occupied = 0;
	vector->del = del;
	vector->array = calloc(vector->capacity, vector->element_size);
	if (!vctrdata(vector))
		return (ERROR);
	return (SUCCESS);
}
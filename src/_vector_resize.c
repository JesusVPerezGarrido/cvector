/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrnew copy 31.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/21 11:43:20 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_int.h"

int _vector_resize(t_vector *vector, size_t count) // TO-DO
{
	void *new_array;

	new_array = calloc(count, vector->element_size);
	if (!new_array)
		return (ERROR);
	memcpy(new_array, vector->array, vector->occupied * vector->element_size);
	free(vector->array);
	vector->array = new_array;
	vector->capacity = count;
	return (SUCCESS); // TO-DO
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vector_resize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:47:07 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	_vector_resize(t_vector *vector, size_t new_size)
{
	void	*new_array;

	if (new_size < MINIMUM_VECTOR_SIZE)
		new_size = MINIMUM_VECTOR_SIZE;
	new_array = calloc(new_size, vector->element_size);
	if (!new_array)
		return (ERROR);
	memcpy(new_array, vector->array, vector->occupied * vector->element_size);
	free(vector->array);
	vector->array = new_array;
	vector->capacity = new_size;
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrinsert_range.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 10:55:19 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/28 11:19:44 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrinsert_range(t_vector *vector, size_t pos, const void *elements,
		size_t count)
{
	size_t	new_capacity;

	if (!vector || !vctrdata(vector) || pos > vctrsize(vector) || !elements
		|| count > vctrmxsize(vector) - vctrsize(vector))
		return (ERROR);
	if (count == 0)
		return (SUCCESS);
	new_capacity = vector->capacity;
	while (new_capacity < vctrsize(vector) + count)
		if (new_capacity * VECTOR_GROWTH_FACTOR <= vctrmxsize(vector))
			new_capacity *= VECTOR_GROWTH_FACTOR;
		else
			return (ERROR);
	if (_vector_resize(vector, new_capacity) == ERROR)
		return (ERROR);
	memmove(_vector_offset(vector, pos + count), _vector_offset(vector, pos), vctrsize(vector) - pos * vector->element_size);
	memcpy(_vector_offset(vector, pos), elements, count * vector->element_size);
	vector->occupied = vector->occupied + count;
	return (SUCCESS);
}

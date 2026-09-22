/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrerase_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/22 16:33:00 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_int.h"

int vctrerase_range(t_vector *vector, size_t first, size_t last)
{
	size_t range_length;

	if (!vctrdata(vector) || first > last || first >= vctrsize(vector) || last >= vctrsize(vector))
		return (ERROR);
	range_length = last - first + 1;
	if (vector->del)
		for (size_t i = 0; i < range_length; i++)
			vector->del(_vector_offset(vector, first + i));
	if (last + 1 < vctrsize(vector))
		for (size_t i = 0; i < vctrsize(vector) - last - 1; i++)
			vctrassign(vector, first + i, vctrat(vector, last + i + 1));
	vector->occupied -= range_length;
	if (_vector_need_shrink(vector))
		return (_vector_resize(vector, vector->occupied * VECTOR_GROWTH_FACTOR));

	return (SUCCESS);
}
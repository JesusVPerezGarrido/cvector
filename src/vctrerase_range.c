/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrerase_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:38:19 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrerase_range(t_vector *vector, size_t first, size_t last)
{
	size_t	range_length;
	size_t	index;

	if (!vctrdata(vector) || first > last
		|| first >= vctrsize(vector) || last >= vctrsize(vector))
		return (ERROR);
	range_length = last - first + 1;
	if (vector->del)
	{
		index = 0;
		while (index < range_length)
		{
			vector->del(_vector_offset(vector, first + index));
			index++;
		}
	}
	if (last + 1 < vctrsize(vector))
	{
		index = 0;
		while (index < vctrsize(vector) - last - 1)
		{
			vctrassign(vector, first + index, vctrat(vector, last + index + 1));
			index++;
		}
	}
	vector->occupied -= range_length;
	if (_vector_need_shrink(vector))
		return (_vector_resize(vector,
				vector->occupied * VECTOR_GROWTH_FACTOR));
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrerase_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 12:30:59 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

static int	_free_elements(t_vector *vector, size_t first, size_t last)
{
	size_t	range_length;
	size_t	index;

	range_length = last - first + 1;
	if (vector->del)
	{
		index = 0;
		while (index < range_length)
		{
			vector->del(vctrat(vector, first + index));
			index++;
		}
	}
	return (SUCCESS);
}

static void	_move_elements(t_vector *vector, size_t first, size_t last)
{
	void	*dst;
	void	*src;
	size_t	size;

	size = (vector->occupied - last - 1) * vector->element_size;
	if (size)
	{
		dst = vctrat(vector, first);
		src = vctrat(vector, last + 1);
		memmove(dst, src, size);
	}
}

int	vctrerase_range(t_vector *vector, size_t first, size_t last)
{
	size_t	new_size;

	if (!vctrdata(vector))
		return (ERROR);
	if (first > last)
		return (ERROR);
	if (last >= vctrsize(vector))
		return (ERROR);
	_free_elements(vector, first, last);
	_move_elements(vector, first, last);
	vector->occupied -= last - first + 1;
	if (_vector_need_shrink(vector))
	{
		new_size = vctrsize(vector) * VECTOR_GROWTH_FACTOR;
		return (_vector_resize(vector, new_size) == ERROR);
	}
	return (SUCCESS);
}

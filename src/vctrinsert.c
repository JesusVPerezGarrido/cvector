/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrinsert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 12:26:30 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

static void	_move_elements(t_vector *vector, size_t pos)
{
	void	*src;
	void	*dst;
	size_t	size;

	size = (vctrsize(vector) - pos) * vector->element_size;
	if (size)
	{
		src = vctrat(vector, pos);
		dst = vctrat(vector, pos + 1);
		memmove(src, dst, size);
	}
}

int	vctrinsert(t_vector *vector, size_t pos, const void *element)
{
	if (!vctrdata(vector))
		return (ERROR);
	if (pos > vctrsize(vector))
		return (ERROR);
	if (pos >= vctrcpcty(vector))
		return (ERROR);
	if (_vector_need_growth(vector))
		_vector_resize(vector, vctrsize(vector) * VECTOR_GROWTH_FACTOR);
	_move_elements(vector, pos);
	memcpy(vctrat(vector, pos), element, vector->element_size);
	vector->occupied++;
	return (SUCCESS);
}

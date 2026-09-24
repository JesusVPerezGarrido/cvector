/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrpop_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 15:23:41 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

static void	_move_elements(t_vector *vector)
{
	void	*dst;
	void	*src;
	size_t	size;

	size = (vector->occupied - 1) * vector->element_size;
	if (size)
	{
		dst = vctrfrnt(vector);
		src = vctrat(vector, 1);
		memmove(dst, src, size);
	}
}

int	vctrpop_front(t_vector *vector)
{
	size_t	new_size;

	if (vctrmpty(vector))
		return (ERROR);
	if (vector->del)
		vector->del(vctrfrnt(vector));
	_move_elements(vector);
	vector->occupied--;
	if (_vector_need_shrink(vector))
	{
		new_size = vector->occupied * VECTOR_GROWTH_FACTOR;
		return (_vector_resize(vector, new_size));
	}
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrerase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 12:14:00 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrerase(t_vector *vector, size_t pos)
{
	size_t	index;
	size_t	new_size;

	if (!vctrdata(vector))
		return (ERROR);
	if (pos >= vctrsize(vector))
		return (ERROR);
	if (vector->del)
		vector->del(vctrat(vector, pos));
	index = pos;
	while (index < vctrsize(vector) - 1)
	{
		vctrassign(vector, index, vctrat(vector, index + 1));
		index++;
	}
	vector->occupied--;
	if (_vector_need_shrink(vector))
	{
		new_size = vector->occupied * VECTOR_GROWTH_FACTOR;
		return (_vector_resize(vector, new_size));
	}
	return (SUCCESS);
}

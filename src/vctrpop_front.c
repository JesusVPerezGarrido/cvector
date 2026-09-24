/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrpop_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:37:01 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrpop_front(t_vector *vector)
{
	size_t	index;

	if (vctrmpty(vector))
		return (ERROR);
	if (vector->del)
		vector->del(vctrfrnt(vector));
	index = 0;
	while (index + 1 < vctrsize(vector))
	{
		vctrassign(vector, index, vctrat(vector, index + 1));
		index++;
	}
	vector->occupied--;
	if (_vector_need_shrink(vector))
		return (_vector_resize(vector,
				vector->occupied * VECTOR_GROWTH_FACTOR));
	return (SUCCESS);
}

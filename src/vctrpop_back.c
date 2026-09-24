/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrpop_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 12:27:57 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrpop_back(t_vector *vector)
{
	size_t	new_size;

	if (!vctrdata(vector) || vctrmpty(vector))
		return (ERROR);
	if (vector->del)
		vector->del(vctrbck(vector));
	vector->occupied--;
	if (_vector_need_shrink(vector))
	{
		new_size = vector->occupied * VECTOR_GROWTH_FACTOR;
		return (_vector_resize(vector, new_size));
	}
	return (SUCCESS);
}

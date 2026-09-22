/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrerase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/22 16:33:02 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_int.h"

int vctrerase(t_vector *vector, size_t pos)
{
	if (!vctrdata(vector) || pos >= vctrsize(vector))
		return (ERROR);
	if (vector->del)
		vector->del(_vector_offset(vector, pos));
	for (size_t i = pos; i < vctrsize(vector) - 1; i++)
		vctrassign(vector, pos, vctrat(vector, pos + 1));
	vector->occupied--;
	if (_vector_need_shrink(vector))
		return (_vector_resize(vector, vector->occupied * VECTOR_GROWTH_FACTOR));

	return (SUCCESS);
}
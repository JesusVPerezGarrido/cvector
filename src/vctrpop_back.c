/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrpop_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:37:14 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrpop_back(t_vector *vector)
{
	if (!vctrdata(vector) || vctrmpty(vector))
		return (ERROR);
	if (vector->del)
		vector->del(vctrbck(vector));
	vector->occupied--;
	if (_vector_need_shrink(vector))
		return (_vector_resize(vector,
				vector->occupied * VECTOR_GROWTH_FACTOR));
	return (SUCCESS);
}

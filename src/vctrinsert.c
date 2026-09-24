/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrinsert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:37:37 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrinsert(t_vector *vector, size_t pos, const void *element)
{
	size_t	index;

	if (!vctrdata(vector) || pos > vctrsize(vector) || pos >= vctrcpcty(vector))
		return (ERROR);
	if (_vector_need_growth(vector))
		_vector_resize(vector, vctrsize(vector) * VECTOR_GROWTH_FACTOR);
	index = vctrsize(vector);
	while (index > pos)
	{
		vctrassign(vector, index, vctrat(vector, index - 1));
		index--;
	}
	if (vctrassign(vector, pos, element) == ERROR)
		return (ERROR);
	vector->occupied++;
	return (SUCCESS);
}

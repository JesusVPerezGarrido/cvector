/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrnew copy 6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/21 11:37:10 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_int.h"

int vctrinsert(t_vector *vector, size_t index, const void *element)
{
	if (!vctrdata(vector) || index > vctrsize(vector) || index >= vctrcpcty(vector))
		return (ERROR);
	if (_vector_need_growth(vector))
		_vector_resize(vector, vctrsize(vector) * VECTOR_GROWTH_FACTOR);
	for (size_t i = vctrsize(vector); i > index; i--)
		vctrassign(vector, i, vctrat(vector, i - 1));
	if (vctrassign(vector, index, element) == ERROR)
		return (ERROR);
	vector->occupied++;
	return (SUCCESS);
}
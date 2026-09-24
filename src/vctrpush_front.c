/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrpush_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:36:11 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrpush_front(t_vector *vector, const void *element)
{
	if (!vctrdata(vector))
		return (ERROR);
	if (_vector_need_growth(vector))
		_vector_resize(vector, vctrsize(vector) * VECTOR_GROWTH_FACTOR);
	if (vctrinsert(vector, 0, element) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

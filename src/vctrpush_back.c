/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrpush_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:33:33 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrpush_back(t_vector *vector, const void *element)
{
	if (!vctrdata(vector))
		return (ERROR);
	if (_vector_need_growth(vector))
		_vector_resize(vector, vctrsize(vector) * VECTOR_GROWTH_FACTOR);
	if (vctrassign(vector, vctrsize(vector), element) == ERROR)
		return (ERROR);
	vector->occupied++;
	return (SUCCESS);
}

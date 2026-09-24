/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrresize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:36:02 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrresize(t_vector *vector, size_t count, const void *value)
{
	if (!vctrdata(vector))
		return (ERROR);
	if (vctrsize(vector) == count)
		return (SUCCESS);
	if (vctrsize(vector) > count)
		if (vctrerase_range(vector, count, vctrsize(vector)) == ERROR)
			return (ERROR);
	if (_vector_resize(vector, count) == ERROR)
		return (ERROR);
	if (value)
	{
		while (vctrsize(vector) < count)
			if (vctrpush_back(vector, value) == ERROR)
				return (ERROR);
	}
	else
	{
		memset(_vector_offset(vector, vctrsize(vector)), 0,
			vector->element_size * (count - vctrsize(vector)));
		vector->occupied = count;
	}
	return (SUCCESS);
}

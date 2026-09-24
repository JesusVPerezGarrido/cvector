/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrresize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 15:22:56 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrresize(t_vector *vector, size_t count, const void *value)
{
	size_t	growth_size;
	
	if (!vctrdata(vector))
		return (ERROR);
	if (vctrsize(vector) == count)
		return (SUCCESS);
	if (vctrsize(vector) > count)
		if (vctrerase_range(vector, count, vctrsize(vector) - 1) == ERROR)
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
		growth_size = (count - vctrsize(vector)) * vector->element_size;
		memset(vctrat(vector, vctrsize(vector)), 0, growth_size);
		vector->occupied = count;
	}
	return (SUCCESS);
}

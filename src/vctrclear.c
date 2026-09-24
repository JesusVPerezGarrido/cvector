/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrclear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:34:12 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrclear(t_vector *vector)
{
	size_t	index;

	if (!vctrdata(vector))
		return (ERROR);
	if (vector->del)
	{
		index = 0;
		while (index < vctrsize(vector))
		{
			vector->del(_vector_offset(vector, index));
			index++;
		}
	}
	vector->occupied = 0;
	return (SUCCESS);
}

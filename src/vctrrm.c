/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrrm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:35:42 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrrm(t_vector *vector)
{
	size_t	index;

	if (!vector)
		return (SUCCESS);
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
	free(vctrdata(vector));
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrnew copy 3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/21 11:36:34 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_int.h"

int vctrrm(t_vector *vector)
{
	if (!vector)
		return (SUCCESS);
	if (!vctrdata(vector))
		return (ERROR);
	if (vector->del)
		for (size_t i = 0; i < vctrsize(vector); i++)
			vector->del(vctrdata(vector) + (i * vector->element_size));
	free(vctrdata(vector));
	return (SUCCESS);
}
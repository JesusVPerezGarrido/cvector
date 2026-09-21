/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrnew copy 26.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/21 11:42:18 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_int.h"

int vctrclear(t_vector *vector)
{
	if (!vctrdata(vector))
		return (ERROR);
	if (vector->del)
		for (size_t i = 0; i < vctrsize(vector); i++)
			vector->del(_vector_offset(vector, i));
	vector->occupied = 0;
	return (SUCCESS);
}
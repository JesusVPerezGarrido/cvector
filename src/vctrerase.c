/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrnew copy 23.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/21 11:41:37 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_int.h"

int vctrerase(t_vector *vector, size_t pos)
{
	if (!vctrdata(vector) || pos >= vctrsize(vector))
		return (ERROR);
	if (vector->del)
		vector->del(_vector_offset(vector, pos));
	for (size_t i = pos; i < vctrsize(vector) - 1; i++)
		vctrassign(vector, pos, vctrat(vector, pos + 1));
	vector->occupied--;
	return (SUCCESS);
}
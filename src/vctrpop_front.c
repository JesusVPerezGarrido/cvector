/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrnew copy 28.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/21 11:42:40 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_int.h"

int vctrpop_front(t_vector *vector)
{
	if (vctrmpty(vector))
		return (ERROR);
	if (vector->del)
		vector->del(vctrfrnt(vector));
	for (size_t i = 0; i + 1 < vctrsize(vector); i++)
		vctrassign(vector, i, vctrat(vector, i + 1));
	vector->occupied--;
	return (SUCCESS);
}
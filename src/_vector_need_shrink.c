/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vector_need_shrink.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:32:06 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

bool	_vector_need_shrink(const t_vector *vector)
{
	return (vctrcpcty(vector) >= MINIMUM_VECTOR_SIZE
		&& vctrsize(vector) >= vctrcpcty(vector) * VECTOR_SHRINK_THRESHOLD);
}

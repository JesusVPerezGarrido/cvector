/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vector_need_shrink.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 12:06:27 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

bool	_vector_need_shrink(const t_vector *vector)
{
	if (vctrcpcty(vector) < MINIMUM_VECTOR_SIZE)
		return (false);
	if (vctrsize(vector) >= vctrcpcty(vector) * VECTOR_SHRINK_THRESHOLD)
		return (false);
	return (true);
}

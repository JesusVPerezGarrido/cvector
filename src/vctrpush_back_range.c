/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrpush_back_range.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 10:55:21 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/28 11:13:06 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrpush_back_range(t_vector *vector, const void *element, size_t count)
{
	if (!vector || !vctrdata(vector))
		return (ERROR);
	return (vctrinsert_range(vector, vector->occupied, element, count));
}

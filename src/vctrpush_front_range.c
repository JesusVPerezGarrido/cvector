/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrpush_front_range.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 10:55:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/28 11:13:07 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrpush_front_range(t_vector *vector, const void *element, size_t count)
{
	if (!vector || !vctrdata(vector))
		return (ERROR);
	return (vctrinsert_range(vector, 0, element, count));
}

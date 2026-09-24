/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrdup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:32:55 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrdup(t_vector *dst, const t_vector *src)
{
	if (!dst || !src || !src->array)
		return (ERROR);
	if (vctrnew(dst, src->occupied * 2, src->element_size, src->del) == ERROR)
		return (ERROR);
	dst->occupied = src->occupied;
	memcpy(dst->array, src->array, dst->occupied * dst->element_size);
	return (SUCCESS);
}

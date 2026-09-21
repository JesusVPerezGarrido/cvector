/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrnew copy 15.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/21 11:39:19 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_int.h"

const void *vctrdata_const(const t_vector *vector)
{
	if (!vector || !vector->array)
		return (NULL);
	return (vector->array);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrassign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:34:02 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrassign(t_vector *vector, size_t index, const void *element)
{
	if (!vctrdata(vector) || index > vctrsize(vector)
		|| index >= vctrcpcty(vector))
		return (ERROR);
	memcpy(_vector_offset(vector, index), element, vector->element_size);
	return (SUCCESS);
}

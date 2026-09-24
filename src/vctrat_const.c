/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrat_const.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:48:32 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

const void	*vctrat_const(const t_vector *vector, size_t index)
{
	if (!vctrdata_const(vector))
		return (NULL);
	if (index >= vctrcpcty(vector))
		return (NULL);
	if (index >= vctrsize(vector))
		return (NULL);
	return (_vector_offset(vector, index));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrfrnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 12:14:52 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

void	*vctrfrnt(t_vector *vector)
{
	if (!vctrdata_const(vector))
		return (NULL);
	if (vctrmpty(vector))
		return (NULL);
	return (_vector_offset(vector, 0));
}

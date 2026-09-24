/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:50:49 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctrcpy(t_vector *dst, const t_vector *src)
{
	if (!vctrdata_const(dst))
		return (ERROR);
	if (!vctrdata_const(src))
		return (ERROR);
	vctrrm(dst);
	return (vctrdup(dst, src));
}

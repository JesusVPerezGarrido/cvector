/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrbck_const.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:49:22 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

const void	*vctrbck_const(const t_vector *vector)
{
	if (!vctrdata_const(vector))
		return (NULL);
	if (vctrmpty(vector))
		return (NULL);
	return (vctrat_const(vector, vctrsize(vector) - 1));
}

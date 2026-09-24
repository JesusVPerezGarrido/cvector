/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctriter_const.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:34:57 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctriter_const(const t_vector *vector, int (*func)(const void *))
{
	size_t	index;

	if (!vctrdata_const(vector))
		return (ERROR);
	index = 0;
	while (index < vctrsize(vector))
	{
		if (func(vctrat_const(vector, index)) == ERROR)
			return (ERROR);
		index++;
	}
	return (SUCCESS);
}

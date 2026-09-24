/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctriter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:35:01 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cvector_int.h"

int	vctriter(t_vector *vector, int (*func)(void *))
{
	size_t	index;

	if (!vctrdata_const(vector))
		return (ERROR);
	index = 0;
	while (index < vctrsize(vector))
	{
		if (func(vctrat(vector, index)) == ERROR)
			return (ERROR);
		index++;
	}
	return (SUCCESS);
}

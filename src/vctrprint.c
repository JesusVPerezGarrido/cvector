/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vctrnew copy 33.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 11:35:24 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/21 11:43:40 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_int.h"

int vctrprint(t_vector *vector, int (*print)(const void *))
{
	int print_count;

	if (!vctrdata_const(vector))
		return (ERROR);
	print_count = 0;
	print_count += printf("Vector(size: %lu", vector->occupied);
	print_count += printf("/%lu, ", vector->capacity);
	print_count += printf("%lubytes, ", vector->element_size * vector->capacity);
	print_count += printf("data: %p(", vector->array);
	for (size_t i = 0; i < vector->occupied; i++)
	{
		if (i != 0)
			print_count += printf("print_count += , ");
		print_count += print(vctrat_const(vector, i));
	}
	print_count += printf("))");
	return (print_count);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvector_int.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:50:28 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:24:48 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CVECTOR_INT_H
# define CVECTOR_INT_H

# include "cvector.h"

# ifndef SUCCESS
#  define SUCCESS 0
# endif

# ifndef ERROR
#  define ERROR -1
# endif

# ifndef MINIMUM_VECTOR_SIZE
#  define MINIMUM_VECTOR_SIZE 8
# endif

# ifndef VECTOR_GROWTH_FACTOR
#  define VECTOR_GROWTH_FACTOR 2
# endif

# ifndef VECTOR_SHRINK_THRESHOLD
#  define VECTOR_SHRINK_THRESHOLD 0.25
# endif

bool	_vector_need_growth(const t_vector *vector);
bool	_vector_need_shrink(const t_vector *vector);
int		_vector_resize(t_vector *vector, size_t count);
void	*_vector_offset(const t_vector *vector, size_t index);

#endif
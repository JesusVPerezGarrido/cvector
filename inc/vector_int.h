/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_int.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:50:28 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/21 11:35:03 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_INT_H
#define VECTOR_INT_H

#include "vector.h"

#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef ERROR
#define ERROR -1
#endif

#ifndef VECTOR_GROWTH_FACTOR
#define VECTOR_GROWTH_FACTOR 2
#endif

#ifndef VECTOR_SHRINK_THRESHOLD
#define VECTOR_SHRINK_THRESHOLD 1 / 4
#endif

// private functions
bool _vector_need_growth(const t_vector *vector);
bool _vector_need_shrink(const t_vector *vector);

int _vector_resize(t_vector *vector, size_t count); // TO-DO

void *_vector_offset(const t_vector *vector, size_t index);

#endif
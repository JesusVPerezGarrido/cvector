/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvector_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 11:20:03 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/24 11:21:38 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CVECTOR_TYPES_H
# define CVECTOR_TYPES_H

# include <stddef.h>

/*
 * A dynamic array container for homogeneous C objects.
 *
 * The vector owns a contiguous block of memory whose size in bytes is defined by
 * element_size. The occupied field tracks the number of valid elements, while
 * capacity tracks the current allocation size. When del is non-NULL, it is used
 * as a custom destructor for individual elements during removal or destruction
 * of the vector.
 */
typedef struct s_vector
{
	void	*array;
	size_t	element_size;
	size_t	capacity;
	size_t	occupied;
	void	(*del)(void *);
}			t_vector;

#endif
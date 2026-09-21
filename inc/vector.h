/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 11:38:33 by jeperez-          #+#    #+#             */
/*   Updated: 2026/09/21 11:34:43 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
	void *array;
	size_t element_size;
	size_t capacity;
	size_t occupied;
	void (*del)(void *);
} t_vector;

/*
 * Create and initialize a vector.
 *
 * The underlying storage is allocated with capacity slots, each of size
 * element_size bytes. If allocation fails, ERROR is returned.
 *
 * @param vector      Pointer to the vector to initialize.
 * @param capacity    Number of elements to allocate initially.
 * @param element_size Size of each element in bytes.
 * @param del         Optional destructor applied to elements before cleanup.
 * @return           SUCCESS on success, ERROR on failure.
 */
int vctrnew(t_vector *vector, size_t capacity, size_t element_size, void (*del)(void *));

/*
 * Duplicate an existing vector into a new one.
 *
 * The destination vector is initialized with a capacity large enough for the
 * source's contents, then copies the raw bytes of the array.
 *
 * @param dst Destination vector to populate.
 * @param src Source vector to duplicate.
 * @return    SUCCESS on success, ERROR on failure.
 */
int vctrdup(t_vector *dst, const t_vector *src);

/*
 * Copy the contents of one vector into another.
 *
 * The destination vector is first destroyed, then rebuilt to match the source's
 * content and configuration.
 *
 * @param dst Destination vector.
 * @param src Source vector to copy.
 * @return    SUCCESS on success, ERROR on failure.
 */
int vctrcpy(t_vector *dst, const t_vector *src);

/*
 * Release every element and free the underlying array.
 *
 * If a destructor was supplied in vctrnew, it is called for each occupied element
 * before the storage is freed.
 *
 * @param vector Vector to destroy.
 * @return      SUCCESS on success, ERROR on failure.
 */
int vctrrm(t_vector *vector);

/*
 * Insert a new value at the end of the vector.
 *
 * The vector grows automatically when needed.
 *
 * @param vector Vector to modify.
 * @param element Pointer to the element to append.
 * @return        SUCCESS on success, ERROR on failure.
 */
int vctrpush_back(t_vector *vector, const void *element);

/*
 * Insert a new value at the beginning of the vector.
 *
 * All existing elements are shifted one slot to the right.
 *
 * @param vector Vector to modify.
 * @param element Pointer to the element to prepend.
 * @return        SUCCESS on success, ERROR on failure.
 */
int vctrpush_front(t_vector *vector, const void *element);

/*
 * Insert an element at an index.
 *
 * index must be in the range [0, occupied]. Values after the insertion point are
 * shifted toward the end of the vector.
 *
 * @param vector Vector to modify.
 * @param index  Position to insert into.
 * @param element Pointer to the value to insert.
 * @return        SUCCESS on success, ERROR on failure.
 */
int vctrinsert(t_vector *vector, size_t index, const void *element);

/*
 * Replace the value stored at a given index without changing the size.
 *
 * @param vector Vector to modify.
 * @param index  Index of the element to replace.
 * @param element Pointer to the replacement value.
 * @return        SUCCESS on success, ERROR on failure.
 */
int vctrassign(t_vector *vector, size_t index, const void *element);

/*
 * Access an element by index.
 *
 * @param vector Vector to access.
 * @param index  Element position.
 * @return       Pointer to the element, or NULL if out of range.
 */
void *vctrat(t_vector *vector, size_t index);

/*
 * Access the first element in the vector.
 *
 * @param vector Vector to access.
 * @return       Pointer to the first element, or NULL if empty.
 */
void *vctrfrnt(t_vector *vector);

/*
 * Access the last element in the vector.
 *
 * @param vector Vector to access.
 * @return       Pointer to the last element, or NULL if empty.
 */
void *vctrbck(t_vector *vector);

/*
 * Return the raw storage buffer.
 *
 * @param vector Vector to query.
 * @return       Pointer to the internal array, or NULL if absent.
 */
void *vctrdata(t_vector *vector);

/*
 * Read-only access to an element by index.
 *
 * @param vector Vector to access.
 * @param index  Element position.
 * @return       Const pointer to the element, or NULL if out of range.
 */
const void *vctrat_const(const t_vector *vector, size_t index);

/*
 * Read-only access to the first element.
 *
 * @param vector Vector to access.
 * @return       Const pointer to the first element, or NULL if empty.
 */
const void *vctrfrnt_const(const t_vector *vector);

/*
 * Read-only access to the last element.
 *
 * @param vector Vector to access.
 * @return       Const pointer to the last element, or NULL if empty.
 */
const void *vctrbck_const(const t_vector *vector);

/*
 * Return the raw read-only storage buffer.
 *
 * @param vector Vector to query.
 * @return       Const pointer to the internal array, or NULL if absent.
 */
const void *vctrdata_const(const t_vector *vector);

/*
 * Check whether the vector currently holds no elements.
 *
 * @param vector Vector to inspect.
 * @return       true if occupied == 0, false otherwise.
 */
bool vctrmpty(const t_vector *vector);

/*
 * Return the number of valid elements currently stored.
 *
 * @param vector Vector to inspect.
 * @return       Number of occupied slots.
 */
size_t vctrsize(const t_vector *vector);

/*
 * Return the number of allocated slots in the backing array.
 *
 * @param vector Vector to inspect.
 * @return       Current capacity.
 */
size_t vctrcpcty(const t_vector *vector);

/*
 * The theoretical maximum number of elements, limited by size_t overflow.
 *
 * @param vector Vector to inspect.
 * @return       Maximum safe element count for this element size.
 */
size_t vctrmxsize(const t_vector *vector);

/*
 * Reserve storage for at least the requested number of elements.
 *
 * If the requested capacity is less than the current size, the call is ignored.
 *
 * @param vector Vector to resize.
 * @param new_cap Desired minimum capacity.
 * @return        SUCCESS on success, ERROR on failure.
 */
int vctrrsrv(t_vector *vector, size_t new_cap);

/*
 * Reduce the backing storage to the current size.
 *
 * This is a best-effort shrink operation intended to reclaim memory without
 * affecting the populated elements.
 *
 * @param vector Vector to shrink.
 * @return       SUCCESS on success, ERROR on failure.
 */
int vctrshrnk(t_vector *vector);

/*
 * Remove all elements from the vector without freeing its storage.
 *
 * If a destructor was configured, it is called for each occupied element before
 * the occupied count is reset to zero.
 *
 * @param vector Vector to clear.
 * @return       SUCCESS on success, ERROR on failure.
 */
int vctrclear(t_vector *vector);

/*
 * Remove the element at a specific index.
 *
 * Elements after the removed item are shifted left to fill the gap.
 *
 * @param vector Vector to modify.
 * @param pos    Index of the element to erase.
 * @return       SUCCESS on success, ERROR on failure.
 */
int vctrerase(t_vector *vector, size_t pos);

/*
 * Remove a contiguous range of elements.
 *
 * The range is inclusive: [first, last].
 *
 * @param vector Vector to modify.
 * @param first  First index of the range to erase.
 * @param last   Last index of the range to erase.
 * @return       SUCCESS on success, ERROR on failure.
 */
int vctrerase_range(t_vector *vector, size_t first, size_t last);

/*
 * Remove the last element from the vector.
 *
 * If a destructor is configured, it is invoked for the removed element.
 *
 * @param vector Vector to modify.
 * @return       SUCCESS on success, ERROR on failure.
 */
int vctrpop_back(t_vector *vector);

/*
 * Remove the first element from the vector.
 *
 * All remaining elements are shifted one slot toward the front.
 *
 * @param vector Vector to modify.
 * @return       SUCCESS on success, ERROR on failure.
 */
int vctrpop_front(t_vector *vector);

/*
 * Change the number of occupied elements.
 *
 * If count is larger than the current size, the vector is extended; if count is
 * smaller, the trailing elements are removed. When value is non-NULL, it is used
 * to initialize newly added entries.
 *
 * @param vector Vector to modify.
 * @param count  New occupied size.
 * @param value  Value used to initialize appended entries, or NULL to zero-fill.
 * @return       SUCCESS on success, ERROR on failure.
 */
int vctrresize(t_vector *vector, size_t count, const void *value);

/*
 * Print the vector contents using a user-provided element formatter.
 *
 * The callback receives a pointer to each element in the vector and is expected to
 * return the number of characters written, following the semantics of printf-like
 * functions.
 *
 * @param vector Vector to print.
 * @param print  Callback used to print a single element.
 * @return       characters written on success, ERROR on failure.
 */
int vctrprint(t_vector *vector, int (*print)(const void *));

#include "vector_int.h"

#endif
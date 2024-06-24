/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:23:01 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/27 22:18:41 by mmassarw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief frees the pointer <ptr> of the given <size> and reallocates it to
 * a new pointer
 * 
 * @param ptr 
 * @param size 
 * @return the reallocated pointer is returned.
 */
void	*ft_realloc(void *ptr, size_t new_size, size_t old_size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (ft_calloc(new_size, 1));
	if (new_size == 0)
	{
		ptr = ft_free(ptr);
		return (NULL);
	}
	new_ptr = ft_calloc(new_size, 1);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	ptr = ft_free(ptr);
	return (new_ptr);
}

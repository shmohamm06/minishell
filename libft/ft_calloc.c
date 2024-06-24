/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:43:43 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:43:44 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates enough space for <nmemb> objects
 * that are <size> bytes of memory each
 * and returns a pointer to the allocated memory.
 * The allocated memory is filled with bytes of value zero.
 * 
 * @param nmemb
 * @param size
 * @return If successful, return a pointer to allocated memory,
 * @return if there is an error, return a NULL pointer.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, (nmemb * size));
	return (p);
}

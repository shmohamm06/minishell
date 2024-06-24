/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:00:12 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/15 18:40:37 by mmassarw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Frees the pointer (ptr). If the pointer is pointing to NULL, it
 * does nothing.
 * 
 * @param ptr 
 * @return NULL. 
 */
void	*ft_free(void *ptr)
{
	if (ptr == NULL)
		return (NULL);
	free(ptr);
	return (NULL);
}

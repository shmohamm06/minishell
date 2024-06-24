/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:43:53 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:43:55 by shmohamm         ###   ########.fr       */
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

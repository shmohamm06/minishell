/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:46:31 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:46:32 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies <n> bytes from memory area <src>
 * to memory area <dest>.  If dst and src overlap, behavior is undefined.
 * 
 * @param dest 
 * @param src 
 * @param n 
 * @return The original value of <dest>.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!(char *) dest && !(char *) src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return ((char *) dest);
}

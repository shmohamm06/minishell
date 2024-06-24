/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:47:07 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:47:08 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies <len> bytes from string <src>
 * to string <dst>. The two strings may overlap.
 *  
 * @param dst 
 * @param src 
 * @param len 
 * @return The original value of <dst>.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!(char *)dst && !(char *)src)
		return (NULL);
	if (dst > src)
	{
		i = len - 1;
		while ((int) i >= 0)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:02:28 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/07 04:53:14 by mmassarw         ###   ########.fr       */
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

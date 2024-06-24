/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:46:22 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:46:23 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of <c>
 * (converted to an unsigned char) in string <s>.
 * 
 * @param s
 * @param c 
 * @param n 
 * @return A pointer to the byte located,
 * or NULL if no such byte exists within <n> bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)s)[i]) == ((unsigned char)c))
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

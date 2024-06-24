/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:55:28 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/07 02:55:00 by mmassarw         ###   ########.fr       */
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

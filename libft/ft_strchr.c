/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:47:55 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:47:56 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of <c>
 * (converted to a char) in the string pointed to by <s>.
 * 
 * @param s 
 * @param c 
 * @return A pointer to the located character,
 * or null if the character does not appear in the string. 
 */
char	*ft_strchr(const char *s, int c)
{
	while ((*s != (char) c) && (*s != 0))
		s++;
	if (*s == (char) c)
		return ((char *)s);
	return (NULL);
}

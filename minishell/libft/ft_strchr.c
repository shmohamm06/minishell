/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:01:47 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/07 03:59:48 by mmassarw         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 07:35:56 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/15 18:12:27 by mmassarw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and copies a substring from the string <s>.
 * The substring begins at index <start> and is of maximum size <len>.
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return the allocated string, or NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	l;
	char	*p;

	l = len;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		l = ft_strlen(s);
	p = (char *) ft_calloc(l + 1, sizeof(char));
	if (!p)
		return (NULL);
	if (start > ft_strlen(s))
	{
		*p = 0;
		return (p);
	}
	ft_strlcpy(p, (s + start), (l + 1));
	return (p);
}

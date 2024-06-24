/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:48:56 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:48:57 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates sufficient memory for
 * a copy of the string <s1> and copies it.
 * 
 * @param s 
 * @return A pointer to the copied string,
 * or NULL if it fails to allocate memory.
 */
char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *) ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

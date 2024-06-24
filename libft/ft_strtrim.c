/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:49:56 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:49:57 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and returns a copy of <s1> with
 * the characters specified in <set> removed from
 * the beginning and the end of the string.
 * 
 * @param s1 
 * @param set 
 * @return The trimmed string. returns NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i >= 0 && ft_strrchr(set, s1[i]))
		i--;
	p = ft_substr(s1, 0, i + 1);
	return (p);
}

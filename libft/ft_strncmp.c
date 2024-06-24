/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:49:39 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:49:40 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Lexicographically compare the null-terminated strings <s1> and <s2>
 * not more than <n> characters
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return An integer greater than, equal to, or less than 0,
 * according as the string <s1> is greater than, equal to,
 * or less than the string <s2>.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && s2[i] && (i < n - 1))
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

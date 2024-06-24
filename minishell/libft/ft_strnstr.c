/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:27:54 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/14 16:11:16 by mmassarw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief locates the first occurrence of the null-terminated string <s2>
 * in the string <s1>, where not more than len characters are searched.
 * Characters that appear after a `\0' character are not searched.
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return If <s2> is an empty string, <s1> is returned;
 * if <s2> occurs nowhere in <s1>, NULL is returned;
 * otherwise a pointer to the first character
 * of the first occurrence of <s2> is returned.
 */
char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	flag;

	i = 0;
	flag = 0;
	if (!s2)
		return ((char *)s1);
	while (i < n && s1[i])
	{
		while (s1[i + flag] == s2[flag] && (i + flag) < n)
		{
			flag++;
			if (s2[flag] == 0)
				return ((char *)s1 + i);
		}
		flag = 0;
		i++;
	}
	return (NULL);
}

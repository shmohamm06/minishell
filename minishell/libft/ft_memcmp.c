/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:57:13 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/07 02:58:04 by mmassarw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares byte string <s1> against
 * byte string <s2>. Both strings are assumed to be <n> bytes long.
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return If the two strings are identical, return 0,
 * otherwise returns the difference between the first two differing bytes.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*j1;
	unsigned char	*j2;

	i = 0;
	j1 = (unsigned char *) s1;
	j2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (j1[i] == j2[i] && (i < n - 1))
		i++;
	return (j1[i] - j2[i]);
}

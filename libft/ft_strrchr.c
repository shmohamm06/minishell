/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:49:50 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:49:51 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the last occurrence of <c>
 * (converted to a char) in the string pointed to by <s>.
 * 
 * @param s 
 * @param c 
 * @return A pointer to the located character,
 * or null if the character does not appear in the string. 
 */
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:47:12 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:47:13 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes <n> bytes of value <c>
 * (converted to an unsigned char) to the string <s>.
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return the string <s>.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*j;

	j = (char *) s;
	while (n > 0)
	{
		*j = c;
		j++;
		n--;
	}
	return (s);
}

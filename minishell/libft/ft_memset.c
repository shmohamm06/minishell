/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:59:01 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/07 04:54:24 by mmassarw         ###   ########.fr       */
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

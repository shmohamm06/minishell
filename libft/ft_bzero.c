/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:43:38 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:43:39 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes <n> zeroed bytes to the string <s>.
 * If <n> is zero, bzero() does nothing.
 * 
 * @param s
 * @param n
 */
void	ft_bzero(void *s, size_t n)
{
	char	*j;

	j = (char *) s;
	while (n-- > 0)
	{
		*j = 0;
		j++;
	}
}

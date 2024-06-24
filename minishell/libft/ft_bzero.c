/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 07:28:18 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/07 02:53:29 by mmassarw         ###   ########.fr       */
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

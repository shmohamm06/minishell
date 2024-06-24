/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 06:33:12 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/07 03:44:52 by mmassarw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief appends string <src> to the end of <dst>.
 * It will append at most <n> - strlen(dst) - 1 characters.
 * It will then NUL-terminate.
 * 
 * @param dst 
 * @param src 
 * @param n 
 * @return if <n> is greater than strlen(dst), returns strlen(src) + <n>.
 * otherwise, return strlen(src) + strlen(dst)
 */
size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	d;
	size_t	s;

	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (n <= d)
		s += n;
	else
	{
		s += d;
		while (src[i] && (d + i) < (n - 1))
		{
			dst[d + i] = src[i];
			i++;
		}
		dst[d + i] = 0;
	}
	return (s);
}

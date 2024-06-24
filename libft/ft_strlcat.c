/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:49:12 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:49:13 by shmohamm         ###   ########.fr       */
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

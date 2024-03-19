/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shahriarshadman <shahriarshadman@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 08:09:00 by shmohamm          #+#    #+#             */
/*   Updated: 2024/01/19 17:28:51 by shahriarsha      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	totalbytes;

	if (size != 0 && count > UINT_MAX / size)
		return (NULL);
	totalbytes = count * size;
	ptr = malloc(totalbytes);
	if (ptr != NULL)
		ft_bzero(ptr, totalbytes);
	return (ptr);
}

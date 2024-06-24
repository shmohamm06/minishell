/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:47:40 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:47:41 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes the string <c>
 * to the file descriptor <fd>.
 * 
 * @param s 
 * @param fd 
 */
int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		ft_putchar_fd(*(s + 1), fd);
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:47:21 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:47:22 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes the character <c>
 * to the file descriptor <fd>.
 * 
 * @param c 
 * @param fd 
 */
int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

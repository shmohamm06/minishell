/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:43:30 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:43:31 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fd_putstr(int fd, char *str)
{
	int	length;
	int	i;

	if (str == NULL)
	{
		write (fd, "(null)", 6);
		return (6);
	}
	else
		length = 0;
	i = -1;
	while (str[++i] != '\0')
		length += fd_putchar(fd, str[i]);
	return (length);
}

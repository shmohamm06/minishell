/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 02:24:18 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/14 02:24:59 by hakaddou         ###   ########.fr       */
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

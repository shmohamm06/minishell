/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 04:18:57 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/14 02:12:05 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fd_parse(int fd, va_list ptr, char c)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += fd_putchar (fd, va_arg (ptr, int));
	else if (c == 's')
		length += fd_putstr (fd, va_arg (ptr, char *));
	else if (c == 'x' || c == 'X')
		length += fd_put_hex (fd, va_arg(ptr, unsigned int), c);
	else if (c == 'd' || c == 'i')
		length += fd_putnbr (fd, va_arg(ptr, int));
	else if (c == 'p')
	{
		length += fd_putstr (fd, "0x");
		length += fd_put_address (fd, va_arg (ptr, unsigned long long));
	}
	else if (c == 'u')
		length += fd_putnbr_u(fd, va_arg (ptr, unsigned int));
	else
		length += fd_putchar (fd, c);
	return (length);
}

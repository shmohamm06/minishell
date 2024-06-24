/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:42:50 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:42:52 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fd_parse(int fd, va_list ptr, char c)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += fd_putchar(fd, va_arg(ptr, int));
	else if (c == 's')
		length += fd_putstr(fd, va_arg(ptr, char *));
	else if (c == 'x' || c == 'X')
		length += fd_put_hex(fd, va_arg(ptr, unsigned int), c);
	else if (c == 'd' || c == 'i')
		length += fd_putnbr(fd, va_arg(ptr, int));
	else if (c == 'p')
	{
		length += fd_putstr(fd, "0x");
		length += fd_put_address(fd, va_arg(ptr, unsigned long long));
	}
	else if (c == 'u')
		length += fd_putnbr_u(fd, va_arg(ptr, unsigned int));
	else
		length += fd_putchar(fd, c);
	return (length);
}

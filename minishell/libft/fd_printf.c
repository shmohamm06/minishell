/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:16:07 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/14 02:25:23 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fd_printf(int fd, const char *str, ...)
{
	int		i;
	va_list	ptr;
	int		length;

	length = 0;
	i = 0;
	va_start (ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			length += fd_putchar (fd, str[i]);
			i++;
		}
		else
		{
			length += fd_parse (fd, ptr, str[i + 1]);
			i += 2;
		}
	}
	va_end (ptr);
	return (length);
}

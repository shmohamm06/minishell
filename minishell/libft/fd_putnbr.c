/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 04:14:14 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/14 02:12:26 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fd_putnbr(int fd, int nb)
{
	int		length;
	char	c;

	length = 0;
	if (nb == -2147483648)
		return (length += fd_putstr(fd, "-2147483648"));
	if (nb < 0)
	{
		length += fd_putchar (fd, '-');
		nb *= -1;
	}
	if (nb >= 10)
		length += fd_putnbr (fd, nb / 10);
	c = (nb % 10) + 48;
	length += fd_putchar(fd, c);
	return (length);
}

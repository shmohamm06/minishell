/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:43:26 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:43:27 by shmohamm         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:43:13 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:43:14 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fd_put_hex(int fd, unsigned int nb, char c)
{
	int			length;
	int			d;
	long long	nbr;
	char		res;

	length = 0;
	if (c == 'x')
		d = 87;
	if (c == 'X')
		d = 55;
	if (nb >= 16)
		length += fd_put_hex (fd, nb / 16, c);
	nbr = nb % 16;
	if (nbr < 10)
		res = nbr + 48;
	if (nbr >= 10)
		res = nbr + d;
	length += fd_putchar(fd, res);
	return (length);
}

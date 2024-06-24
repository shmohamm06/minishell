/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:43:10 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:43:11 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fd_put_address(int fd, unsigned long long nb)
{
	int		length;
	int		nbr;
	char	res;

	length = 0;
	if (nb >= 16)
		length += fd_put_address (fd, nb / 16);
	nbr = nb % 16;
	if (nbr < 10)
		res = nbr + 48;
	if (nbr >= 10)
		res = nbr + 87;
	length += fd_putchar(fd, res);
	return (length);
}

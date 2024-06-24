/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:40:54 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/07 05:45:16 by mmassarw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts the initial portion of the string
 * pointed to by str to int representation.
 * 
 * @param nptr
 * @return The value int
 */
int	ft_atoi(const char *nptr)
{
	int				i;
	unsigned long	n;
	int				sign;

	n = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + nptr[i] % '0';
		i++;
	}
	if (n > INT_MAX && sign == 1)
		return (-1);
	if (n > (unsigned long) INT_MIN && sign == -1)
		return (0);
	return (sign * n);
}

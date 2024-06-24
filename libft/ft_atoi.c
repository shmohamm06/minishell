/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:43:34 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:43:35 by shmohamm         ###   ########.fr       */
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

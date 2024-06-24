/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:51:50 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/07 04:50:12 by mmassarw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_alloc(int n, int *i)
{
	long	nbr;
	char	*p;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		*i += 1;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		*i += 1;
	}
	p = (char *) malloc(*i + 1);
	if (!p)
		return (NULL);
	p[*i] = 0;
	return (p);
}

/**
 * @brief Converts int to str.
 * 
 * @param n
 * @return The value string.
 */
char	*ft_itoa(int n)
{
	int		i;
	char	*p;

	i = 1;
	p = ft_itoa_alloc(n, &i);
	if (!p)
		return (NULL);
	if (n == 0)
		*p = '0';
	if (n < 0)
		p[0] = '-';
	while (n)
	{
		if (n > 0)
			p[--i] = (n % 10) + '0';
		else
			p[--i] = ((n % 10) * -1) + '0';
		n /= 10;
	}
	return (p);
}

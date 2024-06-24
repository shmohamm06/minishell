/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:49:35 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:49:36 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates sufficient memory for
 * a copy of the string <s> and copies it. Applying the
 * function <f> on each character of the copy of the string <s>. 
 * 
 * @param s 
 * @param f 
 * @return the modified copy of the string
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*p;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	p = ft_strdup(s);
	if (!p)
		return (NULL);
	while (p[i])
	{
		f(i, p[i]);
		i++;
	}
	return (p);
}

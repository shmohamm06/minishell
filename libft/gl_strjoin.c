/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:50:28 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:50:29 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;

	i = 0;
	len1 = gl_strlen(s1);
	len2 = gl_strlen(s2);
	if (!len1 && !len2)
		return (0);
	str = ft_calloc(len1 + len2 + 1, 1);
	if (!str)
		return (0);
	str[0] = '\0';
	while (i < len1 + len2)
	{
		if (i < len1)
			str[i] = s1[i];
		if (i >= len1)
			str[i] = s2[i - len1];
		i++;
	}
	str[i] = '\0';
	return (str);
}

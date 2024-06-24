/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:00:42 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/15 18:08:38 by mmassarw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_alloc(char const *s, char c, int *big)
{
	int		i;
	char	**p;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			*big += 1;
		while (s[i] && s[i] != c)
			i++;
	}
	p = (char **) ft_calloc((*big + 1), (sizeof(char *)));
	if (!p)
		return (NULL);
	p[*big] = 0;
	return (p);
}

/**
 * @brief Breaks the <s> string
 * into an array of strings using the <c> delimiter.
 * 
 * @param s 
 * @param c 
 * @return A pointer to the array of strings.
 */
char	**ft_split(char const *s, char c)
{
	int		i;
	int		big;
	int		small;
	char	**p;

	i = 0;
	big = 0;
	p = ft_split_alloc(s, c, &big);
	if (!p)
		return (NULL);
	while (i < big)
	{
		small = 0;
		while (*s == c)
			s++;
		while (s[small] && s[small] != c)
			small++;
		p[i] = (char *) ft_calloc((small + 1), sizeof(char));
		small = 0;
		while (*s && (*s != c))
			p[i][small++] = *s++;
		p[i][small] = 0;
		i++;
	}
	return (p);
}

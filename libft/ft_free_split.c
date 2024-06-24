/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:43:47 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:43:48 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Frees all allocated memory within the double pointer <split>
 * including itself.
 * 
 * @param split 
 */
void	*ft_free_split(char **split)
{
	int	i;

	i = -1;
	if (split)
		while (split[++i])
			split[i] = (char *) ft_free(split[i]);
	split = (char **) ft_free(split);
	return (NULL);
}

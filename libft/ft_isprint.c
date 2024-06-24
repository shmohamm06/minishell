/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:44:15 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:44:16 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Tests for any printing character,
 * including space (' ').
 * The value of the argument must be representable as an unsigned char
 * 
 * @param c
 * @return If true, returns 1.
 * @return if false, returns 0.
 */
int	ft_isprint(int c)
{
	if (c >= ' ' && c <= 126)
		return (1);
	return (0);
}

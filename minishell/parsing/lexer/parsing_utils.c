/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:13:45 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/23 11:13:46 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	skip_quoted_segment(const char *input, unsigned int start_index,
		char quote_char)
{
	unsigned int	length;
	bool			is_quote_open;

	length = 0;
	is_quote_open = false;
	if (input[start_index] == quote_char)
	{
		is_quote_open = true;
		length++;
	}
	while (is_quote_open && input[start_index + length] != '\0')
	{
		length++;
		if (input[start_index + length] == quote_char)
		{
			is_quote_open = false;
			length++;
		}
	}
	return (length);
}

int	is_whitespace(char c)
{
	return (c == ' ' || (c > 8 && c < 14));
}

int	skip_spaces(char *str, int i)
{
	int	j;

	j = 0;
	while (is_whitespace(str[i + j]))
		j++;
	return (j);
}

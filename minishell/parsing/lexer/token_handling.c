/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:14:02 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/23 11:14:03 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tokens	check_token(int c)
{
	static int	token_arr[3][2] = {{'|', PIPE}, {'>', output}, {'<', input}};
	int			i;

	i = 0;
	while (i < 3)
	{
		if (token_arr[i][0] == c)
			return (token_arr[i][1]);
		i++;
	}
	return (0);
}

t_tokens	get_token_type(char *str, int i, int *advance)
{
	t_tokens	token;
	t_tokens	next_token;

	token = check_token(str[i]);
	next_token = check_token(str[i + 1]);
	*advance = 1;
	if (token == output && next_token == output)
	{
		*advance = 2;
		return (append);
	}
	else if (token == input && next_token == input)
	{
		*advance = 2;
		return (heredoc);
	}
	return (token);
}

int	handle_token(char *str, int i, t_lexer **lexer_list)
{
	int			advance;
	t_tokens	token;

	advance = 0;
	token = get_token_type(str, i, &advance);
	if (token)
	{
		if (!add_node(NULL, token, lexer_list))
		{
			return (-1);
		}
		return (advance);
	}
	else
	{
		return (0);
	}
}

int	read_words(int i, char *str, t_lexer **lexer_list)
{
	int	j;

	j = 0;
	while (str[i + j] && !(check_token(str[i + j])))
	{
		j += skip_quoted_segment(str, (unsigned int)(i + j), '\"');
		j += skip_quoted_segment(str, (unsigned int)(i + j), '\'');
		if (is_whitespace(str[i + j]))
			break ;
		else
			j++;
	}
	if (!add_node(ft_substr(str, i, j), 0, lexer_list))
		return (-1);
	return (j);
}

int	token_reader(t_tools *tools)
{
	int	i;
	int	j;

	i = 0;
	while (tools->args[i])
	{
		j = 0;
		i += skip_spaces(tools->args, i);
		if (check_token(tools->args[i]))
			j = handle_token(tools->args, i, &tools->lexer_list);
		else
			j = read_words(i, tools->args, &tools->lexer_list);
		if (j < 0)
			return (0);
		i += j;
	}
	return (1);
}

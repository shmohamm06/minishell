/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:55:06 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/09 11:03:22 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "../execution/execution.h"

char	*add_middle_string(char *start, t_env *match, size_t i, t_mini *mini)
{
	char	*result;

	if (match && match->initialised)
		result = ft_strjoin(match->value, start + i);
	else
		result = ft_strdup(ft_memmove(start, start + i, ft_strlen(start + i)
					+ 1));
	if (!result)
		exit_shell(mini, 137, "Page allocation failure", 2);
	return (result);
}

char	*expand_string(char *quote, t_mini *mini)
{
	char	*start;
	char	*temp;
	size_t	i;
	char	*hold;

	temp = NULL;
	start = ft_strchr(quote, '$');
	if (!start)
		return (quote);
	evaluate_over_character(&i, start + 1, (enum e_tokentype[]){VARIABLE});
	hold = ft_substr(start + 1, 0, i - 1);
	if (hold)
		temp = add_middle_string(start, find_env_variable(hold, mini), i, mini);
	free(hold);
	*start = '\0';
	start = ft_strjoin(quote, temp);
	if (!start)
		exit_shell(mini, 137, "Page allocation failure", 2);
	free(temp);
	free(quote);
	return (start);
}

void	collapse_quotes(t_mini *mini)
{
	t_token	*current;

	current = mini->l_token;
	while (current)
	{
		if (current->type == SINGLE || current->type == DOUBLE)
		{
			ft_memmove(current->content, current->content + 1,
				(ft_strlen(current->content) - 2));
			current->content[ft_strlen(current->content) - 2] = '\0';
			if (current->type == DOUBLE)
				while (ft_strchr(current->content, '$'))
					current->content = expand_string(current->content, mini);
			current->type = WORD;
		}
		current = current->next;
	}
}

void	process_tokens(t_token *head, char ***result, size_t *i)
{
	t_token	*current;

	current = head;
	while (current)
	{
		if (current->type != SPACES)
		{
			if (current->prev && current->prev->type == WORD
				&& current->type != REDIRECTION && current->type != PIPE)
				(*result)[*i - 1] = ft_strjoin_free((*result)[*i - 1],
						current->content);
			else
			{
				*result = ft_realloc(*result, sizeof(char *) * (*i + 2),
						sizeof(char *) * (*i + 1));
				(*result)[(*i)++] = ft_strdup(current->content);
			}
		}
		current = current->next;
	}
}

char	**token_list_to_array(t_token *head)
{
	size_t	i;
	char	**result;

	i = 0;
	result = ft_calloc(1, sizeof(char *));
	process_tokens(head, &result, &i);
	result[i] = NULL;
	return (result);
}

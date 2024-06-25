/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:55:06 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/25 13:03:19 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "../execution/execution.h"

char	*ft_addmidstr(char *start, t_env *match, size_t i, t_mini *mini)
{
	char	*result;

	if (match && match->initialised)
		result = ft_strjoin(match->value, start + i);
	else
		result = ft_strdup(ft_memmove(start, start + i, ft_strlen(start + i)
					+ 1));
	if (!result)
		ft_exit_shell(mini, 137, "Page allocation failure", 2);
	return (result);
}

char	*ft_str_expand(char *quote, t_mini *mini)
{
	char				*start;
	char				*temp;
	enum e_tokentype	type;
	size_t				i;
	char				*hold;

	temp = NULL;
	i = 1;
	type = VARIABLE;
	start = ft_strchr(quote, '$');
	if (start)
	{
		ft_eovchr(&i, start + 1, &type);
		hold = ft_substr(start + 1, 0, i - 1);
		if (type == VARIABLE)
			temp = ft_addmidstr(start, env_already_exist(hold, mini), i, mini);
		hold = (char *)ft_free(hold);
		*start = '\0';
		start = ft_strjoin(quote, temp);
		if (!start)
			ft_exit_shell(mini, 137, "Page allocation failure", 2);
		free(temp);
		free(quote);
		quote = start;
	}
	return (quote);
}

void	ft_collapsequotes(t_mini *mini)
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
					current->content = ft_str_expand(current->content, mini);
			current->type = WORD;
		}
		current = current->next;
	}
}

char	**convert_linked_list(t_token *head)
{
	size_t	i;
	char	*hold;
	char	**result;
	t_token	*current;

	i = 0;
	result = (char **)ft_calloc(1, sizeof(char *));
	current = head;
	while (current != NULL)
	{
		if (current->type != SPACES)
		{
			if (current->prev != NULL && current->prev->type == WORD
				&& current->type != REDIRECTION && current->type != PIPE)
			{
				hold = (char *)ft_strjoin(result[i - 1], current->content);
				result[i - 1] = (char *)ft_free(result[i - 1]);
				result[i - 1] = hold;
			}
			else
			{
				result[i] = (char *)ft_calloc(ft_strlen(current->content) + 1,
						1);
				ft_strcpy(result[i], current->content);
				i++;
				result = (char **)ft_realloc(result, sizeof(char *) * (i + 1),
						sizeof(char *) * (i));
			}
		}
		current = current->next;
	}
	result[i] = NULL;
	return (result);
}

void	ft_tokenize(t_mini *mini)
{
	ft_tokenlist(mini);
	print_linked_list_by_type(mini->l_token);
	if (!ft_evaltokens(mini))
		return ;
	ft_expandvar(mini);
	ft_collapsequotes(mini);
	mini->token = convert_linked_list(mini->l_token);
	printf("\n\n");
}
// print_linked_list_by_type(mini->l_token);

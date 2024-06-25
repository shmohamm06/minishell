/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:52:58 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/25 13:06:00 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "../execution/execution.h"

enum e_tokentype	ft_label_token(char c)
{
	if (c == ' ' || c == '\t')
		return (SPACES);
	if (c == '\'')
		return (SINGLE);
	if (c == '\"')
		return (DOUBLE);
	if (c == '$')
		return (VARIABLE);
	if (c == '<' || c == '>')
		return (REDIRECTION);
	if (c == '|')
		return (PIPE);
	return (WORD);
}

void	ft_eovchr(size_t *i, const char *str, enum e_tokentype *type)
{
	if (!ft_isalpha(*str) && *str != '\'' && *str != '\"' && *str != '_'
		&& *str != '?')
		*type = WORD;
	if (*str != '?')
		while (str[*i - 1] && (ft_isalnum(str[*i - 1]) || str[*i - 1] == '_'))
			*i = *i + 1;
	else
		*i = 2;
}

void	ft_next_token(t_mini *mini, t_token *new, char *line)
{
	enum e_tokentype	type;
	size_t				i;

	type = ft_label_token(*line);
	i = 1;
	if (type == VARIABLE)
		ft_eovchr(&i, line + 1, &type);
	if (type == WORD || type == SPACES)
		while (line[i] && ft_label_token(line[i]) == type)
			i++;
	if (type == REDIRECTION && *line == line[i])
		i++;
	if (type == SINGLE || type == DOUBLE)
		i = (unsigned long)ft_strchr(line + 1, *line) - (unsigned long)line + 1;
	new->type = type;
	new->content = ft_substr(line, 0, i);
	if (!new->content)
		ft_exit_shell(mini, 137, "Page allocation failure", 2);
}

void	ft_tokenlist(t_mini *mini)
{
	t_token	*new;
	t_token	*prev;
	size_t	offset;

	offset = 0;
	prev = NULL;
	while (*(mini->rl + offset))
	{
		new = (t_token *)ft_calloc(1, sizeof(t_token));
		if (!new)
			ft_exit_shell(mini, 137, "Page allocation failure", 2);
		ft_next_token(mini, new, (mini->rl + offset));
		offset += ft_strlen(new->content);
		new->prev = prev;
		if (prev)
			prev->next = new;
		if (!mini->l_token)
			mini->l_token = new;
		prev = new;
	}
}

void	print_linked_list_by_type(t_token *head)
{
	t_token			*current;
	t_token_groups	groups;

	current = head;
	groups.single[0] = '\0';
	groups.doubleq[0] = '\0';
	groups.variable[0] = '\0';
	groups.redirection[0] = '\0';
	groups.pipe[0] = '\0';
	groups.word[0] = '\0';
	while (current != NULL)
	{
		concatenate_token(&groups, current);
		current = current->next;
	}
	print_token_groups(&groups);
}

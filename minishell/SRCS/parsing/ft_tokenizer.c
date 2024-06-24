/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_tokenizer.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mmassarw <mmassarw@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/25 23:12:20 by mmassarw		  #+#	#+#			 */
/*   Updated: 2023/01/27 07:29:21 by mmassarw		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../minishell.h"

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
	if (!ft_isalpha(*str) && *str != '\'' && *str != '\"' \
	&& *str != '_' && *str != '?')
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
		i = (unsigned long) ft_strchr(line + 1, *line) \
		- (unsigned long) line + 1;
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
		new = (t_token *) ft_calloc(1, sizeof(t_token));
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

void print_linked_list_by_type(t_token *head) {
	 t_token *current = head;
	 char single[10000] = "";
	 char doubleq[10000] = "";
	 char variable[10000] = "";
	 char redirection[10000] = "";
	 char pipe[10000] = "";
	 char word[10000] = "";
	 while (current != NULL) {
		 if (current->type == SINGLE) {
			 strcat(single, current->content);
			 strcat(single, " ");
		 } else if (current->type == DOUBLE) {
			 strcat(doubleq, current->content);
			 strcat(doubleq, " ");
		 } else if (current->type == VARIABLE) {
			 strcat(variable, current->content);
			 strcat(variable, " ");
		 } else if (current->type == REDIRECTION) {
			 strcat(redirection, current->content);
			 strcat(redirection, " ");
		 } else if (current->type == PIPE) {
			 strcat(pipe, current->content);
			 strcat(pipe, " ");
		 } else if (current->type == WORD) {
			 strcat(word, current->content);
			 strcat(word, " ");
		 }
		 current = current->next;
	 }
	 if(strlen(single)) printf("[SINGLE] %s\n", single);
	 if(strlen(doubleq)) printf("[DOUBLE] %s\n", doubleq);
	 if(strlen(variable)) printf("[VARIABLE] %s\n", variable);
	 if(strlen(redirection)) printf("[REDIRECTION] %s\n", redirection);
	 if(strlen(pipe)) printf("[PIPE] %s\n", pipe);
	 if(strlen(word)) printf("[WORD] %s\n", word);
}

void	pop_middle_node(t_token **list, t_token *node)
{
	if (*list == NULL || node == NULL)
		return ;
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	if (*list == node)
		*list = node->next;
	node->prev = NULL;
	node->next = NULL;
	ft_free_ltoken(node);
}

bool	ft_evalvar(char *name, t_mini *mini)
{
	char	**split;
	size_t	word_count;
	t_env	*env;

	word_count = 0;
	env = env_already_exist(name, mini);
	if (!env || !env->initialised)
		return (false);
	if (env && env->initialised)
	{
		split = ft_split(env->value, ' ');
		while (split[word_count])
			word_count++;
		ft_free_split(split);
	}
	if (word_count != 1)
		return (false);
	else
		return (true);
}

bool	ft_evalrdr(t_token *head, t_mini *mini)
{
	t_token	*current;

	current = head->next;
	if (!current)
		return (false);
	if (current->type == SPACES)
		current = current->next;
	if (!current || current->type == PIPE || current->type == REDIRECTION)
		return (false);
	while (current && current->type != SPACE && current->type != PIPE \
	&& current->type != REDIRECTION)
	{
		if (current->type == VARIABLE)
			if (!ft_evalvar(current->content, mini))
				return(false);
		current = current->next;
	}
	return (true);
}

bool	ft_evalops(t_token *head, t_mini *mini)
{
	t_token	*current;

	current = head;
	if (current->type == PIPE)
	{
		current = head->next;
		if (!current)
			return (false);
		if (current->type == SPACES)
			current = current->next;
		if (!current || current->type == PIPE)
			return (false);
		return (true);
	}
	else
		return (ft_evalrdr(current, mini));
}

bool	ft_evaltokens(t_mini *mini)
{
	t_token	*current;

	current = mini->l_token;
	while(current)
	{
		if (current->type == PIPE || current->type == REDIRECTION)
			if (!ft_evalops(current, mini))
				{
					fd_printf(2, "minishell: syntax error \
near unexpected token\n");
					g_exit_code = 258;
					return (false);
				}
		if (current->type == SINGLE || current->type == DOUBLE)
			if (!ft_strchr(current->content + 1, *current->content))
				{
					fd_printf(2, "minishell: syntax error \
from open quotes\n");
					g_exit_code = 258;
					return (false);
				}
		current = current->next;
	}
	return (true);
}

void	ft_expandvar(t_mini *mini)
{
	t_token	*current;
	t_env	*l_env;

	current = mini->l_token;
	while (current)
	{
		if (current->type == VARIABLE)
		{
			l_env = env_already_exist(current->content + 1, mini);
			current->content[0] = '\0';
			if ((l_env && l_env->initialised) || *(current->content + 1) == '?')
			{
				current->content = (char *) ft_free(current->content);
				if (l_env)
					current->content = ft_strdup(l_env->value);
				else
					current->content = ft_itoa(g_exit_code);
			}
			current->type = WORD;
		}
		current = current->next;
	}
}

char	*ft_addmidstr(char *start, t_env *match, size_t i, t_mini *mini)
{
	char	*result;

	if (match && match->initialised)
		result = ft_strjoin(match->value, start + i);
	else
		result = ft_strdup(ft_memmove(start, start + i,\
		ft_strlen(start + i) + 1));
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

	i = 1;
	type = VARIABLE;
	start = ft_strchr(quote, '$');
	if (start)
	{
		ft_eovchr(&i, start + 1, &type);
		hold = ft_substr(start + 1, 0, i - 1);
		if (type == VARIABLE)
			temp = ft_addmidstr(start, env_already_exist(hold, mini), i, mini);
		hold = (char *) ft_free(hold);
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
			ft_memmove(current->content, current->content + 1,\
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
	result = (char **) ft_calloc(1, sizeof(char *));
	current = head;
	while (current != NULL)
	{
		if (current->type != SPACES)
		{
			if (current->prev != NULL && current->prev->type == WORD && current->type != REDIRECTION && current->type != PIPE)
			{
				hold = (char *) ft_strjoin(result[i - 1], current->content);
				result[i - 1] = (char *) ft_free(result[i - 1]);
				result[i - 1] = hold;
			}
			else
			{
				result[i] = (char *) ft_calloc(ft_strlen(current->content) + 1, 1);
				ft_strcpy(result[i], current->content);
				i++;
				result = (char **) ft_realloc(result, sizeof(char *) * (i + 1), sizeof(char *) * (i));
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
	ft_expandvar(mini); // split by space and add nodes in the middle
	ft_collapsequotes(mini);
	mini->token = convert_linked_list(mini->l_token);
	printf("\n\n");
	// print_linked_list_by_type(mini->l_token);
}
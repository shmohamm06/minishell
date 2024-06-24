/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_token_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:48:47 by mmassarw          #+#    #+#             */
/*   Updated: 2023/02/01 15:05:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief checks if the <string> is a redirection or not
 * 
 * @param string 
 * @return the an enumiration of the redirect 
 */
int	ft_check_rdr(char *string)
{
	if (!ft_strncmp(string, "<", 2))
		return (INPUT);
	else if (!ft_strncmp(string, ">", 2))
		return (OUTPUT);
	else if (!ft_strncmp(string, "<<", 3))
		return (HEREDOC);
	else if (!ft_strncmp(string, ">>", 3))
		return (APPEND);
	else
		return (NONE);
}

/**
 * @brief iterates through the rdr linked list to fetch the tail.
 * 
 * @param rdr_head 
 * @return a pointer to the tail
 */
t_rdr	*ft_get_rdr_tail(t_rdr *rdr_head)
{
	t_rdr	*rdr_tail;

	rdr_tail = rdr_head;
	while (rdr_tail && rdr_tail->next)
		rdr_tail = rdr_tail->next;
	return (rdr_tail);
}

/**
 * @brief counts how many strings, excluding redirections and their files,
 * but including the NULL terminator.
 * 
 * @param token 
 * @return returns an int representing how many objects to be allocated
 */
int	ft_count_till_pipe(char **token)
{
	int	flag;
	int	count;

	count = 0;
	flag = false;
	while (*token && ft_strncmp(*token, "|", 2))
	{
		if (!ft_check_rdr(*token))
		{
			if (flag == false)
				count++;
			flag = false;
		}
		else
			flag = true;
		token++;
		if (token == NULL)
			break ;
	}
	count++;
	return (count);
}

/**
 * @brief adds a node to the rdr linked list
 * 
 * @param rdr_head 
 * @param rdr_tail 
 * @param token 
 * @param i 
 * @return a pointer to the head of the rdr linked list
 */
t_rdr	*ft_add_to_rdrlist(t_rdr *rdr_head, char **token, int *i, t_mini *mini)
{
	t_rdr	*rdr_new;
	t_rdr	*rdr_tail;

	rdr_tail = ft_get_rdr_tail(rdr_head);
	rdr_new = (t_rdr *) ft_calloc(1, sizeof(t_rdr));
	rdr_new->fd = -2;
	rdr_new->og_fd = -2;
	rdr_new->dup2_fd = -2;
	rdr_new->fdpipe[0] = -2;
	rdr_new->fdpipe[1] = -2;
	if (!rdr_new)
		ft_exit_shell(mini, 137, "Page allocation failure\n", 2);
	rdr_new->e_rdr = ft_check_rdr(token[(i[0])++]);
	rdr_new->file = ft_strdup(token[i[0]]);
	if (!rdr_new->file)
		ft_exit_shell(mini, 137, "Page allocation failure\n", 2);
	rdr_new->next = NULL;
	if (rdr_head == NULL)
		rdr_head = rdr_new;
	else
		rdr_tail->next = rdr_new;
	return (rdr_head);
}

/**
 * @brief parses all the redirections and args in <token> into <cmd->arg>
 * and <cmd->rdr>
 * 
 * @param cmd 
 * @param token 
 * @param j counter for <cmd->arg>
 * @param i counter for <token>
 */
void	ft_populate_cmd(t_mini *mini, t_cmd *cmd, char **token, int i[0])
{
	cmd->rdr = NULL;
	while (token[i[0]] && ft_strncmp(token[i[0]], "|", 2))
	{
		if (ft_check_rdr(token[i[0]]))
			cmd->rdr = ft_add_to_rdrlist(cmd->rdr, token, i, mini);
		else
		{
			cmd->arg[i[1]] = ft_strdup(token[i[0]]);
			if (!cmd->arg[i[1]])
				ft_exit_shell(mini, 137, "Page allocation failure\n", 2);
			(i[1])++;
		}
		(i[0])++;
	}
}

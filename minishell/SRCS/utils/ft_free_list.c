/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:43:27 by mmassarw          #+#    #+#             */
/*   Updated: 2023/02/01 01:05:23 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief frees and sets the linked list <l_cmd> to NULL
 * 
 * @param l_cmd 
 */
void	ft_free_cmd(t_cmd *l_cmd)
{
	t_rdr	*current_rdr;
	t_rdr	*next_rdr;
	t_cmd	*next_cmd;

	while (l_cmd != NULL)
	{
		current_rdr = l_cmd->rdr;
		while (current_rdr != NULL)
		{
			current_rdr->file = (char *) ft_free(current_rdr->file);
			next_rdr = current_rdr->next;
			current_rdr = (t_rdr *) ft_free(current_rdr);
			current_rdr = next_rdr;
		}
		if (l_cmd->arg)
			l_cmd->arg = (char **) ft_free_split(l_cmd->arg);
		next_cmd = l_cmd->next;
		l_cmd = (t_cmd *) ft_free(l_cmd);
		l_cmd = next_cmd;
	}
}

/**
 * @brief frees and sets the linked list <l_env> to NULL
 * 
 * @param l_env 
 */
void	ft_free_env(t_env *l_env)
{
	t_env	*env_head;

	env_head = l_env;
	while (env_head)
	{
		l_env = env_head;
		env_head = l_env->next;
		l_env->key = (char *) ft_free(l_env->key);
		l_env->value = (char *) ft_free(l_env->value);
		l_env = (t_env *) ft_free(l_env);
	}
}

void	ft_free_ltoken(t_token *list)
{
	t_token	*current;
	t_token	*next;

	current = list;
	while (current != NULL)
	{
		next = current->next;
		current->content = (char *) ft_free(current->content);
		current = (t_token *) ft_free(current);
		current = next;
	}
}

/**
 * @brief frees the elemnts that need to be replaced
 * and sets those elements struct <s_mini> to NULL.
 * 
 * @param s_mini 
 */
void	ft_free_cycle(t_mini *s_mini)
{
	ft_free_cmd(s_mini->l_cmd);
	s_mini->l_cmd = NULL;
	ft_free_ltoken(s_mini->l_token);
	s_mini->l_token = NULL;
	s_mini->rl = (char *) ft_free(s_mini->rl);
	s_mini->token = (char **) ft_free_split(s_mini->token);
}

/**
 * @brief frees and sets the struct <s_mini> to NULL
 * 
 * @param s_mini 
 */
void	ft_free_all(t_mini *s_mini)
{
	ft_free_cycle(s_mini);
	ft_free_env(s_mini->l_env);
}

/**
 * @brief frees the struct <s_mini>
 * and exits the program with the exit code <error>
 * 
 * @param s_mini 
 * @param error 
 */
void	ft_exit_shell(t_mini *s_mini, int error, char *p_err, int fd)
{
	g_exit_code = error;
	if (p_err)
		fd_printf(fd, "%s\n", p_err);
	close_all_fds(s_mini);
	ft_free_all(s_mini);
	ft_close(0, 0, NULL);
	ft_close(1, 0, NULL);
	ft_close(2, 0, NULL);
	exit(g_exit_code);
}

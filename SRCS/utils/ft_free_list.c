/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:52:27 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 14:48:50 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "../execution/execution.h"

void	free_command_list(t_cmd *l_cmd)
{
	t_rdr	*current_rdr;
	t_rdr	*next_rdr;
	t_cmd	*next_cmd;

	while (l_cmd != NULL)
	{
		current_rdr = l_cmd->rdr;
		while (current_rdr != NULL)
		{
			current_rdr->file = (char *)ft_free(current_rdr->file);
			next_rdr = current_rdr->next;
			current_rdr = (t_rdr *)ft_free(current_rdr);
			current_rdr = next_rdr;
		}
		if (l_cmd->arg)
			l_cmd->arg = (char **)ft_free_split(l_cmd->arg);
		next_cmd = l_cmd->next;
		l_cmd = (t_cmd *)ft_free(l_cmd);
		l_cmd = next_cmd;
	}
}

void	free_environment_list(t_env *l_env)
{
	t_env	*env_head;

	env_head = l_env;
	while (env_head)
	{
		l_env = env_head;
		env_head = l_env->next;
		l_env->key = (char *)ft_free(l_env->key);
		l_env->value = (char *)ft_free(l_env->value);
		l_env = (t_env *)ft_free(l_env);
	}
}

void	free_token_list(t_token *list)
{
	t_token	*current;
	t_token	*next;

	current = list;
	while (current != NULL)
	{
		next = current->next;
		current->content = (char *)ft_free(current->content);
		current = (t_token *)ft_free(current);
		current = next;
	}
}

void	free_mini_cycle(t_mini *s_mini)
{
	free_command_list(s_mini->l_cmd);
	s_mini->l_cmd = NULL;
	free_token_list(s_mini->l_token);
	s_mini->l_token = NULL;
	s_mini->rl = (char *)ft_free(s_mini->rl);
	s_mini->token = (char **)ft_free_split(s_mini->token);
}

void	free_mini_all(t_mini *s_mini)
{
	free_mini_cycle(s_mini);
	free_environment_list(s_mini->l_env);
}

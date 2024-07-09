/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:09:51 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/09 12:09:52 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "built_ins/built_ins.h"
#include "execution/execution.h"

void	take_input(t_mini *mini)
{
	init_signals();
	g_exit_code = -1;
	while (1)
	{
		mini->rl = readline("➜  src ✗  ");
		if (mini->rl == NULL)
			exit_shell(mini, 0, "exit", 1);
		if (mini->rl[0] != '\0')
			add_history(mini->rl);
		ft_tokenize(mini);
		if (mini->token)
			parse_tokens(mini, mini->token);
		if (mini->l_cmd)
		{
			g_exit_code = 2;
			parse_user_input(mini);
			g_exit_code = -1;
		}
		free_mini_cycle(mini);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;

	(void)argc;
	(void)argv;
	ft_bzero(&mini, sizeof(t_mini));
	ft_parse_env(&mini, (const char **)envp);
	take_input(&mini);
	return (0);
}

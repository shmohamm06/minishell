/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:51:15 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/25 10:53:20 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "built_ins/built_ins.h"

void	take_input(t_mini *mini)
{
	while (1)
	{
		mini->rl = read_line_colored(random_between(1, 6));
		if (mini->rl == NULL)
			ft_exit_shell(mini, 0, "exit", 1);
		if (mini->rl[0] != '\0')
			add_history(mini->rl);
		ft_tokenize(mini);
		if (mini->token)
			ft_parse_token(mini, mini->token);
		if (mini->l_cmd)
			parse_input(mini);
		ft_free_cycle(mini);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;

	(void) argc;
	(void) argv;
	ft_bzero(&mini, sizeof(t_mini));
	ft_parse_env(&mini, (const char **)envp);
	take_input(&mini);
}

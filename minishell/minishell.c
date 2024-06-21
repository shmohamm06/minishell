/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:10:19 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/21 14:20:09 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_ins/built_ins.h"

// void executor(t_simple_cmds *cmd, t_tools *tools)
// {
//     if (is_builtin(cmd, tools)) {
//         return;
//     }

//     pid_t pid = fork();
//     if (pid == 0) {
//         execvp(cmd->name, cmd->args);
//         perror("execvp");
//         exit(EXIT_FAILURE);
//     } else if (pid > 0) {
//         waitpid(pid, NULL, 0);
//     } else {
//         perror("fork");
//     }
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	t_tools			tools;
// 	char			*input;
// 	t_simple_cmds	simple_cmd;
// 	int				i;
// 	char			*token;
// 	int				(*builtin_func)(t_tools * tools, t_simple_cmds
// 							* simple_cmd);

// 	tools.envp = envp;
// 	tools.pwd = getcwd(NULL, 0);
// 	tools.old_pwd = NULL;
// 	tools.heredoc = false;
// 	tools.reset = false;
// 	while (1)
// 	{
// 		input = readline("prompt> ");
// 		if (!input)
// 			break ;
// 		add_history(input);
// 		simple_cmd.args = calloc(10, sizeof(char *));
// 		i = 0;
// 		token = strtok(input, " ");
// 		while (token != NULL)
// 		{
// 			simple_cmd.args[i] = strdup(token);
// 			token = strtok(NULL, " ");
// 			i++;
// 		}
// 		if (simple_cmd.args[0] != NULL)
// 		{
// 			(builtin_func)(t_tools  tools,
// 		t_simple_cmds  simple_cmd) = builtin_arr(simple_cmd.args[0]);
// 			if (builtin_func)
// 			{
// 				builtin_func(&tools, &simple_cmd);
// 			}
// 			else
// 			{
// 				executor(&tools);
// 			}
// 		}
// 		for (int j = 0; j < i; j++)
// 		{
// 			free(simple_cmd.args[j]);
// 		}
// 		free(simple_cmd.args);
// 		free(input);
// 	}
// 	free(tools.pwd);
// 	free(tools.old_pwd);
// 	return (0);
// }

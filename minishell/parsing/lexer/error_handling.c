/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:36:19 by wyaseen           #+#    #+#             */
/*   Updated: 2024/06/23 11:43:58 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parser_error(t_tools *tools, t_lexer *lexer_list)
{
	ft_lexerclear(&lexer_list);
	reset_tools(tools);
}
	// return (EXIT_FAILURE);

int	parser_double_token_error(t_tools *tools, t_lexer *lexer_list,
	t_tokens token)
{
	ft_putstr_fd("minishell: syntax error near unexpected token ",
		STDERR_FILENO);
	if (token == output)
		ft_putstr_fd("'>'\n", STDERR_FILENO);
	else if (token == append)
		ft_putstr_fd("'>>'\n", STDERR_FILENO);
	else if (token == input)
		ft_putstr_fd("'<'\n", STDERR_FILENO);
	else if (token == heredoc)
		ft_putstr_fd("'<<'\n", STDERR_FILENO);
	else if (token == PIPE)
		ft_putstr_fd("'|'\n", STDERR_FILENO);
	else
		ft_putstr_fd("\n", STDERR_FILENO);
	ft_lexerclear(&lexer_list);
	reset_tools(tools);
	return (EXIT_FAILURE);
}

void	lexer_error(t_tools *tools)
{
	ft_lexerclear(&tools->lexer_list);
	reset_tools(tools);
}
	// return (EXIT_FAILURE);

// void reset_tools(t_tools *tools) {
//     // Free the command line arguments if they were dynamically allocated
//     //free(tools->args);
//     tools->args = NULL;

//     // Free each path in the paths array, then the array itself
//     //if (tools->paths) {
//         //for (int i = 0; tools->paths[i] != NULL; i++) {
//             //free(tools->paths[i]);
//         //}
//         //free(tools->paths);
//         //tools->paths = NULL;
//     //}

//     // Simple commands cleanup
//     ft_simple_cmdsclear(&tools->simple_cmds);
// Assuming this function exists and does the comprehensive cleanup

//     // Lexer list cleanup - if it's different from the parser's lexer list
//     ft_lexerclear(&tools->lexer_list);

//     // Clean up pwd and old_pwd strings
//     //free(tools->pwd);
//     tools->pwd = NULL;
//     //free(tools->old_pwd);
//     tools->old_pwd = NULL;

//     // If pid is dynamically allocated (for handling child processes)
//     //free(tools->pid);
//     tools->pid = NULL;

//     // Reset simple boolean flags and counters
//     tools->heredoc = false;
//     tools->reset = false;
//     tools->pipes = 0;
// }

// int	export_error(char *c)
// {
// 	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
// 	if (c)
// 	{
// 		ft_putchar_fd('\'', STDERR_FILENO);
// 		ft_putstr_fd(c, STDERR_FILENO);
// 		ft_putstr_fd("\': is ", STDERR_FILENO);
// 	}
// 	ft_putendl_fd("not a valid identifier", STDERR_FILENO);
// 	return (EXIT_FAILURE);
// }

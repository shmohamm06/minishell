/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyaseen <wyaseen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:50:37 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/22 17:39:47 by wyaseen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/executor.h"
# include "../includes/minishell.h"


int	find_cmd(t_simple_cmds *cmd, t_tools *mini)
{
	int		i;
	char	*mycmd;

	i = 0;
	cmd->str = resplit_str(cmd->str);
	if (!access(cmd->str[0], F_OK))
		execve(cmd->str[0], cmd->str, mini->envp);
	while (mini->paths[i])
	{
		mycmd = ft_strjoin(mini->paths[i], cmd->str[0]);
		if (!access(mycmd, F_OK))
			execve(mycmd, cmd->str, mini->envp);
		free(mycmd);
		i++;
	}
	return (cmd_not_found(cmd->str[0]));
}

void	handle_cmd(t_simple_cmds *cmd, t_tools *tools)
{
	int	exit_code;

	exit_code = 0;
	if (cmd->redirections)
		if (check_redirections(cmd))
			exit(1);
	if (cmd->builtin != NULL)
	{
		exit_code = cmd->builtin(tools, cmd);
		exit(exit_code);
	}
	else if (cmd->str[0][0] != '\0')
		exit_code = find_cmd(cmd, tools);
	exit(exit_code);
}

void	dup_cmd(t_simple_cmds *cmd, t_tools *tools, int end[2], int fd_in)
{
	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
		ft_error(4, tools);
	close(end[0]);
	if (cmd->next && dup2(end[1], STDOUT_FILENO) < 0)
		ft_error(4, tools);
	close(end[1]);
	if (cmd->prev)
		close(fd_in);
	handle_cmd(cmd, tools);
}

void	single_cmd(t_simple_cmds *cmd, t_tools *mini)
{
	int	pid;
	int	status;

	mini->simple_cmds = call_expander(mini, mini->simple_cmds);
	if (cmd->builtin == ft_cd || cmd->builtin == ft_exit
		|| cmd->builtin == ft_export)
	{
		g_global.error_num = cmd->builtin(mini, cmd);
		return ;
	}
	send_heredoc(mini, cmd);
	pid = fork();
	if (pid < 0)
		ft_error(5, mini);
	if (pid == 0)
		handle_cmd(cmd, mini);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
}

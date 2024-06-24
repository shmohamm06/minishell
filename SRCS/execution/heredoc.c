/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaddou <hakaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:27:57 by hakaddou          #+#    #+#             */
/*   Updated: 2023/01/29 19:29:46 by hakaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	null_params(char **tmp, char **total, char **line)
{
	*tmp = NULL;
	*total = NULL;
	*line = NULL;
}

void	take_heredoc_input(t_rdr *rdr)
{
	char	*input;
	char	*total;
	char	*tmp;
	char	*line;

	null_params(&tmp, &total, &line);
	while (1)
	{
		input = readline("> ");
		if (!input)
			break ;
		if (ft_strncmp(input, rdr->file, ft_strlen(rdr->file) + 1) == 0)
			break ;
		tmp = line;
		line = gl_strjoin(input, "\n");
		tmp = ft_free(tmp);
		tmp = total;
		total = gl_strjoin(total, line);
		line = ft_free(line);
		tmp = ft_free(tmp);
		input = ft_free(input);
	}
	input = ft_free(input);
	rdr->file = ft_free(rdr->file);
	rdr->file = total;
}

int	ft_pipe_heredoc(t_rdr *rdr, t_mini *mini, t_cmd *cmd)
{
	pipe(rdr->fdpipe);
	rdr->ret = 0;
	rdr->fork_id = fork();
	if (rdr->fork_id == 0)
	{
		rdr->fdpipe[0] = ft_close(rdr->fdpipe[0], 3, cmd);
		rdr->dup2_fd = dup2(rdr->fdpipe[1], STDOUT_FILENO);
		if (rdr->file)
			fd_printf(STDOUT_FILENO, "%s", rdr->file);
		rdr->fdpipe[1] = ft_close (rdr->fdpipe[1], 3, cmd);
		close_rdr_back(cmd);
		ft_exit_shell(mini, 0, NULL, 2);
	}
	else
	{
		rdr->fdpipe[1] = ft_close (rdr->fdpipe[1], 3, cmd);
		rdr->og_fd = dup(STDIN_FILENO);
		rdr->dup2_fd = dup2(rdr->fdpipe[0], STDIN_FILENO);
		waitpid(rdr->fork_id, &rdr->ret, WEXITSTATUS(rdr->ret));
	}
	return (0);
}

void	handle_heredoc(t_mini *mini)
{
	t_cmd	*cmd;
	t_rdr	*rdr;

	cmd = mini->l_cmd;
	while (cmd)
	{
		rdr = cmd->rdr;
		if (rdr)
		{
			while (rdr)
			{
				if (rdr->e_rdr == HEREDOC)
					take_heredoc_input(rdr);
				rdr = rdr->next;
			}
		}
		cmd = cmd->next;
	}
}

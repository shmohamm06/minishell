/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_parse_token.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mmassarw <mmassarw@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/12 03:14:18 by mmassarw		  #+#	#+#			 */
/*   Updated: 2023/01/15 07:52:33 by mmassarw		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief initiates the variables in <cmd>
 * with the values parsed through <token>
 * 
 * @param cmd 
 * @param token 
 * @return The iteration count of <token>.
 */
int	ft_init_arg_n_rdr(t_mini *mini, t_cmd *cmd, char **token)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	cmd->arg = (char **) ft_calloc(ft_count_till_pipe(token), sizeof(char *));
	cmd->fd_pipe[0] = -2;
	cmd->fd_pipe[1] = -2;
	if (!cmd->arg)
		ft_exit_shell(mini, 137, "malloc fail", 2);
	ft_populate_cmd(mini, cmd, token, i);
	return (i[0]);
}

/**
 * @brief parses through <token>, allocates, and initializes a
 * t_cmd linked list.
 * 
 * @param token 
 * @return the t_cmd linked list.
 */
void	ft_parse_token(t_mini *mini, char **token)
{
	t_cmd	*cmd_new;
	t_cmd	*cmd_tail;

	mini->l_cmd = NULL;
	while (*token)
	{
		cmd_new = (t_cmd *) ft_calloc(1, sizeof(t_cmd));
		if (!cmd_new)
			ft_exit_shell(mini, 137, "malloc fail", 2);
		token += ft_init_arg_n_rdr(mini, cmd_new, token);
		cmd_new->next = NULL;
		if (mini->l_cmd == NULL)
			mini->l_cmd = cmd_new;
		else
			cmd_tail->next = cmd_new;
		cmd_tail = cmd_new;
		if (*token)
			if (!ft_strncmp(*token, "|", 2))
				token++;
	}
}

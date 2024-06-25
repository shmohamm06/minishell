/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:52:31 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/25 13:10:08 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "../execution/execution.h"

/**
 * @brief prints an array of strings
 * 
 * @param split 
 */
void	ft_print_split(char **split)
{
	while (*split)
		printf("%s¶ ", *split++);
}

void	print_rdr(t_rdr	*rdr)
{
	while (rdr != NULL)
	{
		if (rdr->e_rdr == 0)
			printf("NONE to file: %s, ", rdr->file);
		else if (rdr->e_rdr == 1)
			printf("INPUT from file: %s, ", rdr->file);
		else if (rdr->e_rdr == 2)
			printf("OUTPUT to file: %s, ", rdr->file);
		else if (rdr->e_rdr == 3)
			printf("HEREDOC with file: %s, ", rdr->file);
		else if (rdr->e_rdr == 4)
			printf("APPEND to file: %s, ", rdr->file);
		rdr = rdr->next;
	}
}

/**
 * @brief prints the cmd list <s_head>
 * 
 * @param s_head 
 */
void	ft_print_cmd(t_cmd *s_head)
{
	int		list;
	t_cmd	*current;
	t_rdr	*rdr;

	list = 0;
	current = s_head;
	while (current != NULL)
	{
		printf("\n------------ cmd %d -------------\n", ++list);
		if (current->arg[0])
		{
			printf("| Command: %s, args: ", current->arg[0]);
			ft_print_split(current->arg + 1);
		}
		else
			printf("| Command: (null)");
		printf("\n| Redirections: ");
		rdr = current->rdr;
		print_rdr(rdr);
		printf("\n------------ cmd %d -------------\n", list);
		printf("\n\n");
		current = current->next;
	}
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

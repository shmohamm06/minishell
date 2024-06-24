/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:57:41 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/27 19:07:50 by mmassarw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

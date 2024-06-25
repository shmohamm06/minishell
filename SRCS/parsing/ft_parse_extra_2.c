/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_extra_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:29:02 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/25 16:45:20 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../built_ins/built_ins.h"
#include "../execution/execution.h"

char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

void	ft_tokenize(t_mini *mini)
{
	ft_tokenlist(mini);
	print_linked_list_by_type(mini->l_token);
	if (!ft_evaltokens(mini))
		return ;
	ft_expandvar(mini);
	ft_collapsequotes(mini);
	mini->token = convert_linked_list(mini->l_token);
	printf("\n\n");
}
// print_linked_list_by_type(mini->l_token);
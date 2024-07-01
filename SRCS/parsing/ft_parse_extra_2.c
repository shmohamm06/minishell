/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_extra_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:29:02 by shmohamm          #+#    #+#             */
/*   Updated: 2024/07/01 15:38:34 by shmohamm         ###   ########.fr       */
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
	tokenize_input(mini);
	print_token_list_by_type(mini->l_token);
	if (!evaluate_tokens(mini))
		return ;
	expand_variables(mini);
	collapse_quotes(mini);
	mini->token = token_list_to_array(mini->l_token);
}

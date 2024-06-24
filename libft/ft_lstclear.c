/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:44:31 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:44:32 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given node <lst> and
 * every successor of that node, using the function <del>.
 * Finally, the pointer to the list must be set to NULL.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new;

	if (!*lst)
		return ;
	while (*lst)
	{
		new = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = new;
	}
	lst = 0;
}

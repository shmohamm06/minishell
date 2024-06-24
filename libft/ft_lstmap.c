/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:44:50 by shmohamm          #+#    #+#             */
/*   Updated: 2024/06/24 10:44:51 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates the list <lst> and applies the function
 * <f> on the content of each node. Creates a new
 * list resulting of the successive applications of the function <f>.
 * The <del> function is used to delete the content of a node if needed.
 * 
 * @param lst 
 * @param f 
 * @param del 
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew((*f)(lst->content));
		if (!new)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmassarw <mmassarw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:54:35 by mmassarw          #+#    #+#             */
/*   Updated: 2023/01/07 04:44:55 by mmassarw         ###   ########.fr       */
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

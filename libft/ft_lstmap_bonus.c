/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 00:04:34 by mkchikec          #+#    #+#             */
/*   Updated: 2021/11/15 23:29:24 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *)
		, void (*del)(void *))
{
	t_list	*head;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (!head)
	{
		ft_lstdelone(head, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}

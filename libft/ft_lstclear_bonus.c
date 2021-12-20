/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 01:23:32 by mkchikec          #+#    #+#             */
/*   Updated: 2021/11/15 23:29:07 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*prev;

	if (!lst || !del)
		return ;
	list = *lst;
	while (list)
	{
		prev = list;
		list = list->next;
		del(prev->content);
		free(prev);
	}
	*lst = NULL;
}

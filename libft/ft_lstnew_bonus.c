/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 10:08:55 by mkchikec          #+#    #+#             */
/*   Updated: 2021/11/15 23:29:55 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list		*lst;

	lst = ((t_list *)malloc(sizeof(t_list)));
	if (!(lst))
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

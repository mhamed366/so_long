/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:55:35 by mkchikec          #+#    #+#             */
/*   Updated: 2021/11/15 23:39:21 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*str;

	len = ft_strlen(s);
	str = (char *)s;
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return (&str[len]);
		len--;
	}
	return (NULL);
}

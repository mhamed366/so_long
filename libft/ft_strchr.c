/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:23:46 by mkchikec          #+#    #+#             */
/*   Updated: 2021/11/15 23:33:48 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	size_t		len;
	char		*str;

	str = (char *)s;
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (str[i] == (char)c)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

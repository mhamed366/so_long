/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:20:56 by mkchikec          #+#    #+#             */
/*   Updated: 2021/11/15 23:30:35 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			l;

	str = (unsigned char *)s;
	l = 0;
	while (l < n)
	{
		if (str[l] == (unsigned char)c)
			return ((void *)&str[l]);
		l++;
	}
	return (0);
}

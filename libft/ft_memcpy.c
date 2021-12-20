/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:55:46 by mkchikec          #+#    #+#             */
/*   Updated: 2021/11/15 23:30:49 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if ((!dst && !src))
		return (NULL);
	if (ft_memcmp(dst, src, n) == 0)
		return (dst);
	s = (unsigned char *)src;
	d = dst;
	while (n--)
	{
		*(d++) = *(s++);
	}
	return (dst);
}

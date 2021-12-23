/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:30:38 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/23 17:06:21 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_ft_memccpy(void *dst, const void *src, int c, int n)
{
	unsigned char	*src1;
	unsigned char	*dst1;
	int				i;

	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		dst1[i] = src1[i];
		if (src1[i] == (unsigned char)c)
			dst1[i] = src1[i];
		i++;
	}
	return (dst1);
}

int	ft_ft_strlcpy(char *dst, const char *src, int c)
{
	int	i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (i < (int)c - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (c > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*join_char(char **line, const char *cache, int *i)
{
	char	*str;
	int		n;
	int		len;

	n = -1;
	len = ft_strlen(*line) + ft_strlen(cache) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	if (*line)
	{
		while ((*line)[++n])
			str[n] = (*line)[n];
		while (cache[*i] && cache[*i] != '\n')
		{
			str[n] = cache[*i];
			n++;
			*i = *i + 1;
		}
	}
	str[n] = '\0';
	free(*line);
	return (str);
}

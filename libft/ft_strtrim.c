/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 07:27:33 by mkchikec          #+#    #+#             */
/*   Updated: 2021/11/15 23:43:51 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iter(char c, char const *set)
{
	int	len;

	len = -1;
	while (set[++len])
		if (c == set[len])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	l;
	size_t	r;
	size_t	len;

	if (!s1)
		return (NULL);
	l = 0;
	while (l < ft_strlen(s1) && iter(s1[l], set))
		l++;
	r = ft_strlen(s1) - 1;
	while (r && iter(s1[r], set))
		r--;
	if (r >= l)
	{
		res = (char *)malloc(sizeof(char) * ((len = r - l + 1) + 1));
		if (!(res))
			return (NULL);
		r = 0;
		while (r < len)
			res[r++] = s1[l++];
		res[r] = '\0';
		return (res);
	}
	return (ft_strdup("\0"));
}

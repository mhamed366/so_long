/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 09:11:29 by mkchikec          #+#    #+#             */
/*   Updated: 2021/11/15 23:28:51 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int c)
{
	unsigned long int	a;
	int					i;

	if (c == -2147483648)
		return (11);
	i = 0;
	a = 1;
	if (c == 0)
		return (1);
	if (c < 0)
	{
		c *= -1;
		i++;
	}
	while (a <= (unsigned long int)c)
	{
		a *= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int c)
{
	int		i;
	int		k;
	char	*res;

	res = (char *)malloc(((i = len(c)) + 1) * sizeof(char));
	if (!(res))
		return (0);
	res[i--] = '\0';
	if (c == 0)
		res[0] = '0';
	k = 0;
	if (c < 0)
	{
		c *= -1;
		k++;
		res[0] = '-';
	}
	while (i >= k && c != -2147483648)
	{
		res[i--] = (c % 10) + 48;
		c /= 10;
	}
	if (c == -2147483648)
		ft_strcpy(res, "-2147483648");
	return (res);
}

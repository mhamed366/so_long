/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:17:05 by mkchikec          #+#    #+#             */
/*   Updated: 2021/11/30 20:02:48 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	neg;

	neg = 1;
	res = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * neg);
}

long long	ft_atoi_long(const char *str)
{
	long long	res;
	int			neg;

	neg = 1;
	res = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * neg);
}

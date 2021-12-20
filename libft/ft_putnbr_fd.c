/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:30:26 by mkchikec          #+#    #+#             */
/*   Updated: 2021/11/15 23:31:07 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t	res;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		res = (size_t)n * -1;
	}
	else
		res = (size_t)n;
	if (res >= 10)
		ft_putnbr_fd(res / 10, fd);
	ft_putchar_fd((res % 10) + 48, fd);
}

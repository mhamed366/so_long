/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:38:59 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/23 19:07:34 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	quit_program(int keycode, t_all *all)
{
	(void) all;
	(void) keycode;
	ft_putstr_fd("\n", 1);
	free_all(all->map, all->collectibles, all->exits);
	exit(1);
}

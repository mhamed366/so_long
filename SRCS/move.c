/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:32:20 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/23 16:55:37 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	on_collectibe(t_all *all)
{
	t_counter	counter;

	counter.i = -1;
	while (++counter.i < all->collectibles->count)
	{
		if (all->player->pos_x == all->collectibles->pos_x[counter.i]
			&& all->player->pos_y == all->collectibles->pos_y[counter.i])
		{
			all->collectibles->collected++;
			all->collectibles->pos_x[counter.i] = -100;
			all->collectibles->pos_y[counter.i] = -100;
		}	
	}
}

int	on_exit(t_all *all)
{
	t_counter	counter;

	counter.i = -1;
	while (++counter.i < all->exits->count)
	{
		if (all->player->pos_x == all->exits->pos_x[counter.i]
			&& all->player->pos_y == all->exits->pos_y[counter.i]
			&& all->collectibles->count == all->collectibles->collected)
		{
			mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
			mlx_string_put(all->mlx->mlx, all->mlx->mlx_win,
				(all->map->width / 2) * 64, (all->map->height / 2) * 64,
				0XFFFFFF, "You Won");
			return (1);
		}	
	}
	return (0);
}

void	key_events(int keycode, t_all *all)
{
	if (keycode == 13
		&& all->map->map[all->player->pos_y - 1][all->player->pos_x] != '1')
		all->player->pos_y--;
	else if (keycode == 1
		&& all->map->map[all->player->pos_y + 1][all->player->pos_x] != '1')
		all->player->pos_y++;
	else if (keycode == 0
		&& all->map->map[all->player->pos_y][all->player->pos_x - 1] != '1')
		all->player->pos_x--;
	else if (keycode == 2
		&& all->map->map[all->player->pos_y][all->player->pos_x + 1] != '1')
		all->player->pos_x++;
	else if (keycode == 53)
	{
		mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
		exit(1);
	}
}

int	move(int keycode, t_all *all)
{
	key_events(keycode, all);
	on_collectibe(all);
	if (!on_exit(all))
	{
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		draw_wec(all->mlx, all->map, all->collectibles, all->exits);
		draw_player(all->mlx, all->player);
		draw_lim(all->mlx, all->map);
	}
	return (1);
}

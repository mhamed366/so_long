/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:32:20 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/22 21:33:23 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	on_collectibe(int keycode, t_all *all)
{
	t_counter counter;

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

int	on_exit(int keycode, t_all *all)
{
	t_counter counter;

	counter.i = -1;
	while (++counter.i < all->exits->count)
	{
		printf("exit posx, posy : %d %d\n",all->exits->pos_x[counter.i],all->exits->pos_y[counter.i]);
		printf("player posx, posy : %d %d\n",all->player->pos_x,all->player->pos_y);
		printf("%d %d\n", all->collectibles->collected, all->collectibles->count);
		if (all->player->pos_x == all->exits->pos_x[counter.i]
			&& all->player->pos_y == all->exits->pos_y[counter.i]
			&& all->collectibles->count == all->collectibles->collected)
		{
			mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
			mlx_string_put(all->mlx->mlx, all->mlx->mlx_win, (all->map->width / 2) * 64, (all->map->height / 2) * 64, 0XFFFFFF, "You Won");
			return (1);
		}	
	}
	return (0);
}

void	key_events(int keycode, t_all *all)
{
	if (keycode == 13 && all->map->map[all->player->pos_y - 1][all->player->pos_x] != '1')
		all->player->pos_y--;
	else if(keycode == 1 && all->map->map[all->player->pos_y + 1][all->player->pos_x] != '1')
		all->player->pos_y++;
	else if(keycode == 0 && all->map->map[all->player->pos_y][all->player->pos_x - 1] != '1')
		all->player->pos_x--;
	else if(keycode == 2 && all->map->map[all->player->pos_y][all->player->pos_x + 1] != '1')
		all->player->pos_x++;
	else if(keycode == 53)
	{
		mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
		exit(1);
	}
}
// 13 0 1 2
int	move(int keycode, t_all *all)
{
	key_events(keycode, all);
	on_collectibe(keycode, all);
	if (!on_exit(keycode, all))
	{
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		draw_WEC(all->mlx, all->map, all->player, all->collectibles, all->exits);
		draw_player(all->mlx, all->map, all->player, all->collectibles, all->exits);
		draw_lim(all->mlx, all->map, all->player, all->collectibles, all->exits);
	}
	
	return (1);
}
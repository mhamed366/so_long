/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:34:22 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/23 17:17:54 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_lim2(t_mlx *mlx, t_map *map, t_counter *counter)
{
	if (counter->i == 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_images.wall_ul, 0, counter->i * 64);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_images.wall_ur, (map->width - 1) * 64, counter->i * 64);
	}
	else if (counter->i == map->height - 1)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_images.wall_dl, 0, counter->i * 64);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_images.wall_dr, (map->width - 1) * 64, counter->i * 64);
	}
	else
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_images.wall_l, 0, counter->i * 64);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_images.wall_r, (map->width - 1) * 64, counter->i * 64);
	}
}

void	draw_lim(t_mlx *mlx, t_map *map)
{
	t_counter	counter;

	counter.i = -1;
	while (++counter.i < map->height)
		draw_lim2(mlx, map, &counter);
	counter.i = 0;
	while (++counter.i < map->width - 1)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_images.wall_u, counter.i * 64, 0);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			g_images.wall_d, counter.i * 64, (map->height - 1) * 64);
	}
}

void	draw_wec(t_mlx *mlx, t_map *map,
	t_collectibles *collectibles, t_exits *exits)
{
	char		*s;
	t_counter	counter;

	s = ft_itoa(collectibles->collected);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 64, 10, 0xFFFFFF, s);
	free(s);
	counter.i = -1;
	while (++counter.i < map->walls_count)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, g_images.wall_02,
			map->walls_x[counter.i] * 64, map->walls_y[counter.i] * 64);
	counter.i = -1;
	while (++counter.i < exits->count)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, g_images.exit,
			exits->pos_x[counter.i] * 64, exits->pos_y[counter.i] * 64);
	counter.i = -1;
	while (++counter.i < collectibles->count)
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, g_images.collectible,
			collectibles->pos_x[counter.i] * 64,
			collectibles->pos_y[counter.i] * 64);
}

void	draw_player(t_mlx *mlx, t_player *player)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, g_images.player,
		player->pos_x * 64, player->pos_y * 64);
}

void	draw(t_map *map, t_player *player,
	t_collectibles *collectibles, t_exits *exits)
{
	t_all	all;

	g_mlx.mlx = mlx_init();
	g_mlx.mlx_win = mlx_new_window(g_mlx.mlx,
			map->width * 64, map->height * 64, "SO_LONG");
	set_images(&g_mlx);
	draw_lim(&g_mlx, map);
	draw_player(&g_mlx, player);
	draw_wec(&g_mlx, map, collectibles, exits);
	all.player = player;
	all.collectibles = collectibles;
	all.exits = exits;
	all.map = map;
	all.mlx = &g_mlx;
	mlx_hook(g_mlx.mlx_win, 02, 1L << 0, move, &all);
	mlx_loop(g_mlx.mlx);
}

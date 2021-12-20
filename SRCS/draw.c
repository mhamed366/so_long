/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:34:22 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/20 21:56:25 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_images(t_mlx *mlx, t_map *map, t_player *player, t_collectibles *collectibles, t_exits *exits)
{
	// map->wall_d = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_d.xpm", &mlx->width, &mlx->height);
	// map->wall_dl = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_dl.xpm", &mlx->width, &mlx->height);
	map->wall_dr = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_dr.xpm", &mlx->width, &mlx->height);
	map->wall_l = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_l.xpm", &mlx->width, &mlx->height);
	map->wall_r = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_r.xpm", &mlx->width, &mlx->height);
	map->wall_u = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_u.xpm", &mlx->width, &mlx->height);
	map->wall_ul = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_ul.xpm", &mlx->width, &mlx->height);
	map->wall_ur = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_ur.xpm", &mlx->width, &mlx->height);
	player->img = mlx_xpm_file_to_image(mlx->mlx, "./sprites/player_01.xpm", &mlx->width, &mlx->height);
	exits->img = mlx_xpm_file_to_image(mlx->mlx, "./sprites/door_01.xpm", &mlx->width, &mlx->height);
	collectibles->img = mlx_xpm_file_to_image(mlx->mlx, "./sprites/plant_02.xpm", &mlx->width, &mlx->height);
}

void	draw_lim(t_mlx *mlx, t_map *map, t_player *player, t_collectibles *collectibles, t_exits *exits)
{
	t_counter counter;

	counter.i = -1;
	while (++counter.i < map->height)
	{
		
	}
	counter.i = -1;
	while (++counter.i < map->width)
	{
		
	}
}

void	draw(t_mlx *mlx, t_map *map, t_player *player, t_collectibles *collectibles, t_exits *exits)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, map->width * 64, map->height * 64, "SO_LONG");
	set_images(mlx, map, player, collectibles, exits);
	player->img = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_d.xpm", &mlx->width, &mlx->height);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, map->wall_l, 0, 0);
	// mlx_loop_hook(mlx.mlx, animate, &mlx);
	mlx_loop(mlx->mlx);
}
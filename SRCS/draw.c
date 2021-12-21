/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:34:22 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/21 22:03:30 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_images(t_mlx *mlx, t_map *map, t_player *player, t_collectibles *collectibles, t_exits *exits)
{
	images.wall_dr = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_dr.xpm", &mlx->width, &mlx->height);
	images.wall_l = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_l.xpm", &mlx->width, &mlx->height);
	images.wall_r = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_r.xpm", &mlx->width, &mlx->height);
	images.wall_u = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_u.xpm", &mlx->width, &mlx->height);
	images.wall_ul = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_ul.xpm", &mlx->width, &mlx->height);
	images.wall_ur = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_ur.xpm", &mlx->width, &mlx->height);
	images.wall_d = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_d.xpm", &mlx->width, &mlx->height);
	images.wall_dl = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_dl.xpm", &mlx->width, &mlx->height);
	images.player = mlx_xpm_file_to_image(mlx->mlx, "./sprites/player_01.xpm", &mlx->width, &mlx->height);
	images.exit = mlx_xpm_file_to_image(mlx->mlx, "./sprites/door_01.xpm", &mlx->width, &mlx->height);
	images.collectible = mlx_xpm_file_to_image(mlx->mlx, "./sprites/plant_02.xpm", &mlx->width, &mlx->height);
}

void	draw_lim(t_mlx *mlx, t_map *map, t_player *player, t_collectibles *collectibles, t_exits *exits)
{
	t_counter counter;

	counter.i = -1;
	while (++counter.i < map->height)
	{
		if (counter.i == 0)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, images.wall_ul, 0, counter.i * 64);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, images.wall_ur, (map->width - 1) * 64, counter.i * 64);
		}
		else if(counter.i == map->height - 1)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, images.wall_dl, 0, counter.i * 64);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, images.wall_dr, (map->width - 1) * 64, counter.i * 64);
		}
		else
		{
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, images.wall_l, 0, counter.i * 64);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, images.wall_r, (map->width - 1) * 64, counter.i * 64);
		}
	}
	counter.i = 0;
	while (++counter.i < map->width - 1)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, images.wall_u, counter.i * 64, 0);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, images.wall_d, counter.i * 64, (map->height - 1) * 64);
	}
}

void	draw_player(t_mlx *mlx, t_map *map, t_player *player, t_collectibles *collectibles, t_exits *exits)
{
	printf("%d %d\n", player->pos_x, player->pos_y);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, images.player, player->pos_x * 64, player->pos_y * 64);
}

void	draw(t_mlx *mlx, t_map *map, t_player *player, t_collectibles *collectibles, t_exits *exits)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, map->width * 64, map->height * 64, "SO_LONG");
	set_images(mlx, map, player, collectibles, exits);
	draw_lim(mlx, map, player, collectibles, exits);
	draw_player(mlx, map, player, collectibles, exits);
	// player->img = mlx_xpm_file_to_image(mlx->mlx, "./sprites/wall_dr.xpm", &mlx->width, &mlx->height);
	// mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, images.wall_dr, 0, 0);
	// mlx_loop_hook(mlx.mlx, animate, &mlx);
	mlx_loop(mlx->mlx);
}
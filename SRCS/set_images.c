/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:18:01 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/23 17:18:13 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_images(t_mlx *mlx)
{
	g_images.wall_dr = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/wall_dr.xpm", &mlx->width, &mlx->height);
	g_images.wall_l = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/wall_l.xpm", &mlx->width, &mlx->height);
	g_images.wall_r = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/wall_r.xpm", &mlx->width, &mlx->height);
	g_images.wall_u = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/wall_u.xpm", &mlx->width, &mlx->height);
	g_images.wall_ul = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/wall_ul.xpm", &mlx->width, &mlx->height);
	g_images.wall_ur = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/wall_ur.xpm", &mlx->width, &mlx->height);
	g_images.wall_d = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/wall_d.xpm", &mlx->width, &mlx->height);
	g_images.wall_dl = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/wall_dl.xpm", &mlx->width, &mlx->height);
	g_images.wall_02 = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/wall_02.xpm", &mlx->width, &mlx->height);
	g_images.player = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/player_01.xpm", &mlx->width, &mlx->height);
	g_images.exit = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/door_01.xpm", &mlx->width, &mlx->height);
	g_images.collectible = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/plant_03.xpm", &mlx->width, &mlx->height);
}

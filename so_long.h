/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:10:25 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/20 18:53:01 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

# define NOT_RECTANGULAR -1
# define ALLOCATION_ERROR -2
# define UNALLOWED_CHAR -3
# define INVALID_PLAYER -4
# define INVALID_EXIT -5
# define INVALID_COLLECTIBLE -5
# define MAP_NOT_CLOSED -6
# define OK 1

typedef struct mlx {
	void *mlx;
	void *mlx_win;
	int height;
	int width;
} t_mlx;

typedef struct map {
	int	walls_count;
	int	empty_count;
	int	*empty_x;
	int *empty_y;
	int	*walls_x;
	int	*walls_y;
	int fd;
	int	height;
	int	width;
	char **map;
} t_map;

typedef struct player {
	int count;
	int	pos_x;
	int pos_y;
	void *img;
} t_player;

typedef struct collectibles {
	int	count;
	int	*pos_x;
	int	*pos_y;
	int	collected;
} t_collectibles;

typedef struct exits {
	int	count;
	int	*pos_x;
	int	*pos_y;
} t_exits;

typedef struct counter
{
	int i;
	int j;
	int k;
	int count_wall;
	int	count_empty;
	int count_exit;
	int count_collectible;
} t_counter;


int		parse_map(char *file, t_map *map);
int		check_map(t_map *map, t_player *player, t_collectibles *collectibles, t_exits *exits);
int		store_positions(t_map *map, t_player *player, t_collectibles *collectibles, t_exits *exits);
int		check_components(t_map *map, t_player *player, t_collectibles *collectibles, t_exits *exits);

#endif
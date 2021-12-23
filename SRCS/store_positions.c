/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:08:07 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/23 17:03:11 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	count every component to allocate the size of it
*/
void	count_components(t_map *map, t_player *player,
	t_collectibles *collectibles, t_exits *exits)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->height - 1)
	{
		j = 0;
		while (++j < map->width - 1)
		{
			if (map->map[i][j] == 'C')
				collectibles->count++;
			else if (map->map[i][j] == 'E')
				exits->count++;
			else if (map->map[i][j] == '1')
				map->walls_count++;
			else if (map->map[i][j] == '0')
				map->empty_count++;
			else if (map->map[i][j] == 'P')
				player->count++;
		}
	}
}

/*
	allocating positions
*/
int	allocate_pos(t_map *map, t_player *player,
	t_collectibles *collectibles, t_exits *exits)
{
	(void) player;
	map->empty_x = (int *)malloc(sizeof(int) * map->empty_count);
	map->empty_y = (int *)malloc(sizeof(int) * map->empty_count);
	map->walls_y = (int *)malloc(sizeof(int) * map->walls_count);
	map->walls_x = (int *)malloc(sizeof(int) * map->walls_count);
	collectibles->pos_x = (int *)malloc(sizeof(int) * collectibles->count);
	collectibles->pos_y = (int *)malloc(sizeof(int) * collectibles->count);
	exits->pos_x = (int *)malloc(sizeof(int) * exits->count);
	exits->pos_y = (int *)malloc(sizeof(int) * exits->count);
	if (!map->empty_x || !map->empty_y || !map->walls_x
		|| !map->walls_y || !collectibles->pos_x
		|| !collectibles->pos_y || !exits->pos_x || !exits->pos_y)
		return (0);
	return (1);
}

void	increment_count(t_map *map, t_exits *exits,
		t_collectibles *collectibles, t_counter *counter)
{
	if (map->map[counter->i][counter->j] == 'C')
	{
		collectibles->pos_x[counter->count_collectible] = counter->j;
		collectibles->pos_y[counter->count_collectible++] = counter->i;
	}
	else if (map->map[counter->i][counter->j] == 'E')
	{
		exits->pos_x[counter->count_exit] = counter->j;
		exits->pos_y[counter->count_exit++] = counter->i;
	}
	else if (map->map[counter->i][counter->j] == '1')
	{
		map->walls_x[counter->count_wall] = counter->j;
		map->walls_y[counter->count_wall++] = counter->i;
	}
	else if (map->map[counter->i][counter->j] == '0')
	{
		map->empty_x[counter->count_empty] = counter->j;
		map->empty_y[counter->count_empty++] = counter->i;
	}
}

void	store_pos(t_map *map, t_player *player,
		t_collectibles *collectibles, t_exits *exits)
{
	t_counter	counter;

	counter.count_wall = 0;
	counter.count_empty = 0;
	counter.count_collectible = 0;
	counter.count_exit = 0;
	counter.i = 0;
	while (++counter.i < map->height - 1)
	{
		counter.j = 0;
		while (++counter.j < map->width - 1)
		{
			increment_count(map, exits, collectibles, &counter);
			if (map->map[counter.i][counter.j] == 'P')
			{
				player->pos_x = counter.j;
				player->pos_y = counter.i;
			}
		}
	}
}

int	store_positions(t_map *map, t_player *player,
	t_collectibles *collectibles, t_exits *exits)
{
	int	i;

	i = -1;
	count_components(map, player, collectibles, exits);
	if (!allocate_pos(map, player, collectibles, exits))
		return (ALLOCATION_ERROR);
	store_pos(map, player, collectibles, exits);
	return (OK);
}

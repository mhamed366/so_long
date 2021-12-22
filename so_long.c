/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:09:38 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/22 23:18:19 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_vars(t_map *map, t_player *player, t_collectibles *collectibles, t_exits *exits)
{
	map->empty_count = 0;
	map->walls_count = 0;
	player->count = 0;
	collectibles->count = 0;
	collectibles->collected = 0;
	exits->count = 0;
}

int main(int ac, char **av)
{
	t_mlx mlx;
	t_map map;
	t_player player;
	t_collectibles collectibles;
	t_exits exits;
	
	if (ac != 2)
	{
		write(1,"",5);
		return (0);
	}
	set_vars(&map, &player, &collectibles, &exits);
	if (parse_map(av[1], &map) != OK)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	printf("check map: %d",check_map(&map, &player, &collectibles, &exits));
	printf("check comp: %d",check_components(&map, &player, &collectibles, &exits));
	draw(&mlx, &map, &player, &collectibles, &exits);
}
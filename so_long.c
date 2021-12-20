/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:09:38 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/20 21:41:00 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_vars(t_map *map, t_player *player, t_collectibles *collectibles, t_exits *exits)
{
	map->empty_count = 0;
	map->walls_count = 0;
	player->count = 0;
	collectibles->count = 0;
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
	
	// printf("%d\n", map.height);
	// for (int i=0;i<map.height;i++)
	// 	printf("%s\n",map.map[i]);
	// for (int i=0;i<map.height;i++)
	// 	free(map.map[i]);
	// for (int i =0;i<exits.count;i++)
	// 	printf("%d ", exits.pos_x[i]);
	// printf("\n");
	// for (int i =0;i<exits.count;i++)
	// 	printf("%d ", exits.pos_y[i]);
	// printf("\n");
	// printf("%d %d",player.pos_x,player.pos_y);
	// printf("collectibles : %d\nexits : %d\nwalls : %d\nempty : %d\n",collectibles.count,exits.count,map.walls_count,map.empty_count);
	// while(1);
}
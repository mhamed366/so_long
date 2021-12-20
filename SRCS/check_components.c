/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:45:06 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/20 21:11:39 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_components(t_map *map, t_player *player, t_collectibles *collectibles, t_exits *exits)
{
	t_counter counter;

	printf("count: %d\n", player->count);
	if (player->count != 1)
		return (INVALID_PLAYER);
	if	(exits->count < 1)
		return (INVALID_EXIT);
	if (collectibles->count < 1)
		return (INVALID_COLLECTIBLE);
	counter.i = -1;
	while (++counter.i < map->height)
	{
		if (map->map[counter.i][0] != '1')
			return (MAP_NOT_CLOSED);
		if (map->map[counter.i][map->width - 1] != '1')
			return (MAP_NOT_CLOSED);
	}
	counter.i = -1;
	while (++counter.i < map->width)
	{
		if (map->map[0][counter.i] != '1')
			return (MAP_NOT_CLOSED);
		if (map->map[map->height - 1][counter.i] != '1')
			return (MAP_NOT_CLOSED);
	}
	return (1);
}
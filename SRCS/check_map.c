/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:09:00 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/20 18:54:11 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_chars(char *line)
{
	int i;

	i = -1;
	while (++i < (int)ft_strlen(line))
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C' && line[i] != 'E' && line[i] != 'P')
		{
			printf("char : %c\n", line[i]);
			return (0);
		}
	}
	return (1);	
}

/*
	return -1 if not rectangular
	return -2 if it has unallowed chars
	return -3 if malloc returns NULL
	return 1 if successful
*/
int	check_map(t_map *map, t_player *player, t_collectibles *collectibles, t_exits *exits)
{
	int i;
	int	j;

	i = -1;
	while(++i < map->height)
	{
		j = -1;
		map->width = ft_strlen(map->map[0]);
		if (map->width != (int)ft_strlen(map->map[i]))
			return (NOT_RECTANGULAR);
		if (!check_chars(map->map[i]))
			return (UNALLOWED_CHAR);
	}
	return (store_positions(map, player, collectibles, exits));
}
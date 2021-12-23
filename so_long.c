/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:09:38 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/23 19:11:46 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_vars(t_map *map, t_player *player,
		t_collectibles *collectibles, t_exits *exits)
{
	map->empty_count = 0;
	map->won = 0;
	map->walls_count = 0;
	player->count = 0;
	collectibles->count = 0;
	collectibles->collected = 0;
	exits->count = 0;
}

void	manage_errors(t_errors *errors)
{
	if (errors->check_comp == INVALID_EXT || errors->check_map == -8
		|| errors->parse_map == INVALID_EXT)
		ft_putstr_fd("\tThe map extension must be .ber\n", 1);
	else if (errors->check_comp == NOT_RECTANGULAR || errors->check_map == -1
		|| errors->parse_map == NOT_RECTANGULAR)
		ft_putstr_fd("\tThe map must be rectangular.\n", 1);
	else if (errors->check_comp == ALLOCATION_ERROR || errors->check_map == -2
		|| errors->parse_map == ALLOCATION_ERROR)
		ft_putstr_fd("\tInsufficient memory or invalid map.\n", 1);
	else if (errors->check_comp == UNALLOWED_CHAR || errors->check_map == -3
		|| errors->parse_map == UNALLOWED_CHAR)
		ft_putstr_fd("\tThe map contains unallowed characters.\n", 1);
	else if (errors->check_comp == INVALID_PLAYER || errors->check_map == -4
		|| errors->parse_map == INVALID_PLAYER)
		ft_putstr_fd("\tNumber of players is invalid.\n", 1);
	else if (errors->check_comp == INVALID_EXIT || errors->check_map == -5
		|| errors->parse_map == INVALID_EXIT)
		ft_putstr_fd("\tInvalid Exit\n", 1);
	else if (errors->check_comp == -6 || errors->check_map == -6
		|| errors->parse_map == INVALID_COLLECTIBLE)
		ft_putstr_fd("\tNumber of collectibles is invalid.\n", 1);
	else if (errors->check_comp == MAP_NOT_CLOSED || errors->check_map == -7
		|| errors->parse_map == MAP_NOT_CLOSED)
		ft_putstr_fd("\tThe map is not closed.\n", 1);
}

void	free_all(t_map *map, t_collectibles *collectibles, t_exits *exits)
{
	free(map->map);
	free(map->empty_x);
	free(map->empty_y);
	free(map->walls_y);
	free(map->walls_x);
	free(collectibles->pos_x);
	free(collectibles->pos_y);
	free(exits->pos_x);
	free(exits->pos_y);
}

int	main(int ac, char **av)
{
	t_map			map;
	t_player		player;
	t_collectibles	collectibles;
	t_exits			exits;
	t_errors		errors;

	if (ac != 2)
	{
		write(1, "Error\n", 5);
		return (0);
	}
	set_vars(&map, &player, &collectibles, &exits);
	errors.parse_map = parse_map(av[1], &map);
	errors.check_map = check_map(&map, &player, &collectibles, &exits);
	errors.check_comp = check_components(&map, &player, &collectibles, &exits);
	if (errors.parse_map != OK || errors.check_map != OK
		|| errors.check_comp != OK)
	{
		free_all(&map, &collectibles, &exits);
		write(1, "Error:", 7);
		manage_errors(&errors);
		exit(1);
	}
	draw(&map, &player, &collectibles, &exits);
	free_all(&map, &collectibles, &exits);
}

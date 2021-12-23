/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:32:20 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/23 19:14:46 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	on_collectibe(t_all *all)
{
	t_counter	counter;

	counter.i = -1;
	while (++counter.i < all->collectibles->count)
	{
		if (all->player->pos_x == all->collectibles->pos_x[counter.i]
			&& all->player->pos_y == all->collectibles->pos_y[counter.i])
		{
			all->collectibles->collected++;
			all->collectibles->pos_x[counter.i] = -100;
			all->collectibles->pos_y[counter.i] = -100;
		}	
	}
}

int	on_exit(t_all *all)
{
	t_counter	counter;

	counter.i = -1;
	while (++counter.i < all->exits->count)
	{
		if (all->player->pos_x == all->exits->pos_x[counter.i]
			&& all->player->pos_y == all->exits->pos_y[counter.i]
			&& all->collectibles->count == all->collectibles->collected)
		{
			mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
			mlx_string_put(all->mlx->mlx, all->mlx->mlx_win,
				(all->map->width / 2) * 64, (all->map->height / 2) * 64,
				0XFFFFFF, "You Won");
			all->map->won = 1;
			return (1);
		}	
	}
	return (0);
}

void	moves_count(int moves_counter)
{
	char	*s;

	s = ft_itoa(moves_counter);
	ft_putstr_fd("Moves count: ", 1);
	ft_putstr_fd(s, 1);
	ft_putstr_fd("\r", 1);
	free(s);
}

void	key_events(int keycode, t_all *all)
{
	static int	moves_counter;

	if (keycode == 13 && !all->map->won
		&& all->map->map[all->player->pos_y - 1][all->player->pos_x] != '1')
		all->player->pos_y--;
	else if (keycode == 1 && !all->map->won
		&& all->map->map[all->player->pos_y + 1][all->player->pos_x] != '1')
		all->player->pos_y++;
	else if (keycode == 0 && !all->map->won
		&& all->map->map[all->player->pos_y][all->player->pos_x - 1] != '1')
		all->player->pos_x--;
	else if (keycode == 2 && !all->map->won
		&& all->map->map[all->player->pos_y][all->player->pos_x + 1] != '1')
		all->player->pos_x++;
	else if (keycode == 53)
	{
		ft_putstr_fd("\n", 1);
		free_all(all->map, all->collectibles, all->exits);
		mlx_destroy_window(all->mlx->mlx, all->mlx->mlx_win);
		exit(1);
	}
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		if (!all->map->won)
			moves_counter++;
	moves_count(moves_counter);
}

int	move(int keycode, t_all *all)
{
	key_events(keycode, all);
	on_collectibe(all);
	if (!on_exit(all))
	{
		mlx_clear_window(all->mlx->mlx, all->mlx->mlx_win);
		draw_wec(all->mlx, all->map, all->collectibles, all->exits);
		draw_player(all->mlx, all->player);
		draw_lim(all->mlx, all->map);
	}
	return (1);
}

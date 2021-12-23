/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:43:34 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/23 18:19:45 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	lines_count(char *file)
{
	int		fd;
	int		read_ret;
	char	c;
	int		count;

	fd = open(file, O_RDONLY);
	count = 0;
	if (!fd)
		return (-1);
	while (1)
	{
		read_ret = read(fd, &c, 1);
		if (read_ret == 0)
			break ;
		if (read_ret < 0)
			return (-1);
		if (c == '\n')
			count++;
	}
	close(fd);
	return (count + 1);
}

int	parse_map(char *file, t_map *map)
{
	int	i;

	if (ft_strncmp(".ber", ft_strrchr(file, '.'), 4))
		return (INVALID_EXT);
	map->fd = open(file, O_RDONLY);
	map->height = lines_count(file);
	map->map = (char **)malloc(sizeof(char *) * map->height + 1);
	if (!map->map)
		return (ALLOCATION_ERROR);
	i = -1;
	while (get_next_line(map->fd, &(map->map[++i])))
		continue ;
	close(map->fd);
	return (OK);
}

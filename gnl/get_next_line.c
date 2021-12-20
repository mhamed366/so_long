/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:30:00 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/19 21:22:54 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		malloc_check(char **line, char **cache, int fd, int *r)
{
	if (line == NULL)
		return (-1);
	if (!(*line = ft_strdup("")))
		return (-1);
	*r = 1;
	if (!*(cache))
	{
		if (fd < 0 || fd > 256)
			return (-1);
		if (!(*(cache) = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
			return (-1);
		*r = read(fd, *(cache), BUFFER_SIZE);
		*(cache[0] + *r) = '\0';
		if (*r <= 0)
			return (*r);
	}
	return (0);
}

static int		read_cache(char **cache, int fd, int *i, int *r)
{
	*r = read(fd, *(cache), BUFFER_SIZE);
	*(cache[0] + *r) = '\0';
	if (*r == 0)
		*(cache[0]) = '\0';
	*i = 0;
	if (*r < 0)
		free(*cache);
	return (*r);
}

void			free_null(char **str)
{
	free(*str);
	*str = NULL;
}

int				get_next_line(int fd, char **line)
{
	static char *cache[256];
	int			i;
	int			r;

	i = 0;
	if ((malloc_check(&(*line), &(cache[fd]), fd, &r)) == -1)
		return (-1);
	while (*(cache[fd] + i) != '\n')
	{
		if (*(cache[fd] + i) == '\0')
			if ((read_cache(&(cache[fd]), fd, &i, &r)) == -1)
				return (-1);
		if (r <= 0)
			break ;
		if (*(cache[fd] + i) != '\n')
			*line = join_char(line, (cache[fd] + i), &i);
	}
	cache[fd] = ft_memccpy(cache[fd], (cache[fd] + i + 1), '\n',
			ft_strlen(cache[fd]));
	if (r <= 0 || (cache[0] == NULL && *line[0] == '\0' && r == 0))
	{
		free_null(&(cache[fd]));
		return (r == 0 || *line[0] == '\0') ? 0 : -1;
	}
	return (1);
}
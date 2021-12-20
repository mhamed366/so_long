/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkchikec <mkchikec@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 11:30:10 by mkchikec          #+#    #+#             */
/*   Updated: 2021/12/20 21:15:54 by mkchikec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

int		get_next_line(int fd, char **line);
void	*ft_ft_memccpy(void *dst, const void *src, int c, int n);
int		ft_ft_strlcpy(char *dst, const char *src, int c);
char	*ft_strdup(const char *s1);
char	*join_char(char **line, const char *cache, int *i);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 01:35:25 by abenamar          #+#    #+#             */
/*   Updated: 2023/01/13 03:49:10 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_line(char **line, char *buf)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	if (!(*line))
	{
		*line = malloc(1 * sizeof(char));
		**line = '\0';
		return (0);
	}
	i = 0;
	while (buf[i] && buf[i] != '\n')
		++i;
	len = ft_strlen(*line);
	tmp = malloc((len + i + 2) * sizeof(char));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, *line, len + 1);
	ft_strlcpy(tmp + len, buf, i + 2);
	free(*line);
	*line = tmp;
	if (buf[i] == '\n' && ++i)
		return (ft_strlcpy(buf, buf + i, BUFFER_SIZE), 1);
	return (ft_strlcpy(buf, buf + i, BUFFER_SIZE), 0);
}

static void	reset_buffer(char **buf)
{
	free(*buf);
	*buf = NULL;
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	int			read_size;
	char		*line;

	if (!buf)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (NULL);
		*buf = '\0';
	}
	line = NULL;
	while (!get_line(&line, buf))
	{
		if (!*buf)
		{
			read_size = read(fd, buf, BUFFER_SIZE);
			if (read_size <= 0)
				return (free(line), reset_buffer(&buf), NULL);
			buf[read_size] = '\0';
		}
	}
	if (!*buf)
		reset_buffer(&buf);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 01:35:25 by abenamar          #+#    #+#             */
/*   Updated: 2023/01/15 01:12:48 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	init_str(char **str, size_t size)
{
	*str = malloc(size * sizeof(char));
	if (!*str)
		return (0);
	**str = '\0';
	return (1);
}

static int	update_line(char **line, size_t len, char *buf, size_t i)
{
	char	*tmp;

	tmp = malloc((len + i + 1) * sizeof(char));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, *line, len + 1);
	free(*line);
	ft_strlcpy(tmp + len, buf, i + 1);
	*line = tmp;
	return (1);
}

static int	process_buffer(char *buf, char **line)
{
	size_t	i;

	if (!*line)
		return (!init_str(line, 1));
	if (!*buf)
		return (0);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		++i;
	if (!update_line(line, ft_strlen(*line), buf, i + 1))
		return (0);
	if (buf[i] == '\n')
		return (ft_strlcpy(buf, buf + i + 1, BUFFER_SIZE), 1);
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

	if (fd < 0 || (!buf && !init_str(&buf, BUFFER_SIZE + 1)))
		return (NULL);
	line = NULL;
	while (!process_buffer(buf, &line))
	{
		if (!*buf)
		{
			read_size = read(fd, buf, BUFFER_SIZE);
			if (*line && !read_size)
				return (reset_buffer(&buf), line);
			else if (read_size <= 0)
				return (reset_buffer(&buf), free(line), NULL);
			buf[read_size] = '\0';
		}
	}
	if (!*buf)
		reset_buffer(&buf);
	return (line);
}

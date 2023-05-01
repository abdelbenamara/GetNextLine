/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:09:03 by abenamar          #+#    #+#             */
/*   Updated: 2023/05/01 16:55:07 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static uint8_t	ft_buffer_isready(char **buffer, const int fd)
{
	if (buffer[fd])
		return (1);
	buffer[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(buffer[fd]))
		return (0);
	*(buffer[fd]) = '\0';
	return (1);
}

static uint8_t	ft_line_init(char **line, size_t len)
{
	*line = malloc((len + LINE_SIZE + 1) * sizeof(char));
	if (!*line)
		return (0);
	**line = '\0';
	return (1);
}

static uint8_t	ft_line_update(char **line, size_t len, char *buf, size_t idx)
{
	char	*tmp;

	if (buf[idx] != '\n'
		&& !(len + idx + 1 >= (len / LINE_SIZE + 1) * LINE_SIZE))
		ft_strlcpy(*line + len, buf, idx + 2);
	else
	{
		if (buf[idx] == '\n')
		{
			tmp = malloc((len + idx + 2) * sizeof(char));
			if (!tmp)
				return (0);
		}
		else if (!ft_line_init(&tmp, ((len + idx) / LINE_SIZE + 1) * LINE_SIZE))
			return (0);
		ft_strlcpy(tmp, *line, len + 1);
		ft_strlcpy(tmp + len, buf, idx + 2);
		free(*line);
		*line = tmp;
	}
	return (1);
}

static uint8_t	ft_eol_in_buffer(char **line, char *buf, size_t *line_len)
{
	size_t	idx;
	char	*tmp;

	if (!**line && !*buf)
		return (0);
	idx = 0;
	while (buf[idx] && buf[idx] != '\n')
		++idx;
	if (!idx && !*buf)
	{
		tmp = malloc((*line_len + 1) * sizeof(char));
		if (!tmp)
			return (0);
		ft_strlcpy(tmp, *line, *line_len + 1);
		return (free(*line), *line = tmp, 1);
	}
	else if (!ft_line_update(line, *line_len, buf, idx))
		return (0);
	*line_len += idx;
	if (buf[idx] == '\n')
		return (ft_strlcpy(buf, buf + idx + 1, BUFFER_SIZE), 1);
	return (ft_strlcpy(buf, buf + idx, BUFFER_SIZE), 0);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX] = {0};
	char		*line;
	size_t		line_len;
	ssize_t		read_size;

	line_len = 0;
	if (!ft_line_init(&line, line_len))
		return (NULL);
	if (fd < 0 || fd >= OPEN_MAX || !ft_buffer_isready(buffer, fd))
		return (free(line), NULL);
	while (!ft_eol_in_buffer(&line, buffer[fd], &line_len))
	{
		if (!*buffer[fd])
		{
			read_size = read(fd, buffer[fd], BUFFER_SIZE);
			if ((!*line && !read_size) || read_size < 0)
				return (free(buffer[fd]), buffer[fd] = NULL, free(line), NULL);
			buffer[fd][read_size] = '\0';
		}
	}
	if (!*buffer[fd])
		return (free(buffer[fd]), buffer[fd] = NULL, line);
	return (line);
}

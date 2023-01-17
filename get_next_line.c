/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 01:35:25 by abenamar          #+#    #+#             */
/*   Updated: 2023/01/17 02:20:53 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static uint8_t	ft_buf_init(t_buf **buf, int fd)
{
	t_buf	*new;

	new = malloc(sizeof(t_buf));
	if (!new)
		return (0);
	new->fd = fd;
	new->content = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new->content)
		return (free(new), 0);
	*new->content = '\0';
	new->next = NULL;
	*buf = new;
	return (1);
}

static uint8_t	ft_buf_poll(t_buf **lst, const int fd)
{
	t_buf	*buf;
	t_buf	*prev;

	buf = *lst;
	prev = NULL;
	while (buf)
	{
		if (buf->fd == fd)
		{
			if (prev)
			{
				prev->next = buf->next;
				buf->next = *lst;
			}
			*lst = buf;
			return (1);
		}
		prev = buf;
		buf = prev->next;
	}
	if (!ft_buf_init(&buf, fd))
		return (0);
	buf->next = *lst;
	*lst = buf;
	return (1);
}

static uint8_t	ft_buf_to_line(t_buf *buf, char **line)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	if (!*buf->content)
		return (0);
	i = 0;
	while (buf->content[i] && buf->content[i] != '\n')
		++i;
	len = ft_strlen(*line);
	tmp = malloc((len + i + 2) * sizeof(char));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, *line, len + 1);
	free(*line);
	ft_strlcpy(tmp + len, buf->content, i + 2);
	*line = tmp;
	if (buf->content[i] == '\n')
		return (ft_strlcpy(buf->content, buf->content + i + 1, BUFFER_SIZE), 1);
	return (ft_strlcpy(buf->content, buf->content + i, BUFFER_SIZE), 0);
}

static void	ft_buf_pop(t_buf **lst)
{
	t_buf	*buf;

	if (*lst)
	{
		buf = *lst;
		*lst = buf->next;
		free(buf->content);
		free(buf);
	}
}

char	*get_next_line(int fd)
{
	static t_buf	*buf = NULL;
	char			*line;
	ssize_t			read_size;

	line = malloc(1 * sizeof(char));
	if (!line)
		return (NULL);
	if (fd < 0 || !ft_buf_poll(&buf, fd))
		return (ft_buf_pop(&buf), free(line), NULL);
	*line = '\0';
	while (!ft_buf_to_line(buf, &line))
	{
		if (!*buf->content)
		{
			read_size = read(fd, buf->content, BUFFER_SIZE);
			if (*line && !read_size)
				return (ft_buf_pop(&buf), line);
			else if (read_size <= 0)
				return (ft_buf_pop(&buf), free(line), NULL);
			buf->content[read_size] = '\0';
		}
	}
	if (!*buf->content)
		return (ft_buf_pop(&buf), line);
	return (line);
}

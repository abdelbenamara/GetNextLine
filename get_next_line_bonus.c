/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:09:03 by abenamar          #+#    #+#             */
/*   Updated: 2023/01/18 00:42:39 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static uint8_t	ft_dfb_lstadd_first(t_list **lst, const int fd)
{
	t_list	*new;
	t_dfb	*content;

	content = malloc(sizeof(t_dfb));
	if (!content)
		return (0);
	content->fd = fd;
	content->buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!content->buffer)
		return (free(content), 0);
	*content->buffer = '\0';
	new = ft_lstnew(content);
	if (!new)
		return (free(content->buffer), free(content), 0);
	ft_lstadd_front(lst, new);
	return (1);
}

static uint8_t	ft_dfb_lstpeek(t_list **lst, const int fd)
{
	t_list	*item;
	t_list	*prev;

	item = *lst;
	prev = NULL;
	while (item)
	{
		if (((t_dfb *) item->content)->fd == fd)
		{
			if (prev)
			{
				prev->next = item->next;
				item->next = *lst;
				*lst = item;
			}
			return (1);
		}
		prev = item;
		item = prev->next;
	}
	if (!ft_dfb_lstadd_first(lst, fd))
		return (0);
	return (1);
}

static void	ft_dfb_lstpop(t_list **lst)
{
	t_list	*item;

	if (*lst)
	{
		item = *lst;
		*lst = item->next;
		free(((t_dfb *) item->content)->buffer);
		free(item->content);
		free(item);
	}
}

static uint8_t	ft_line_buffer_sync(char **line, char *buffer)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	if (!*buffer)
		return (0);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	len = ft_strlen(*line);
	tmp = malloc((len + i + 2) * sizeof(char));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, *line, len + 1);
	free(*line);
	ft_strlcpy(tmp + len, buffer, i + 2);
	*line = tmp;
	if (buffer[i] == '\n')
		return (ft_strlcpy(buffer, buffer + i + 1, BUFFER_SIZE), 1);
	return (ft_strlcpy(buffer, buffer + i, BUFFER_SIZE), 0);
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;
	ssize_t			read_size;

	line = malloc(1 * sizeof(char));
	if (!line)
		return (NULL);
	if (fd < 0 || !ft_dfb_lstpeek(&lst, fd))
		return (ft_dfb_lstpop(&lst), free(line), NULL);
	*line = '\0';
	while (!ft_line_buffer_sync(&line, ((t_dfb *) lst->content)->buffer))
	{
		if (!*((t_dfb *) lst->content)->buffer)
		{
			read_size = read(fd, ((t_dfb *) lst->content)->buffer, BUFFER_SIZE);
			if (*line && !read_size)
				return (ft_dfb_lstpop(&lst), line);
			else if (read_size <= 0)
				return (ft_dfb_lstpop(&lst), free(line), NULL);
			((t_dfb *) lst->content)->buffer[read_size] = '\0';
		}
	}
	if (!*((t_dfb *) lst->content)->buffer)
		return (ft_dfb_lstpop(&lst), line);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:10:03 by abenamar          #+#    #+#             */
/*   Updated: 2023/01/17 01:49:56 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4096
# endif

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_buf
{
	int				fd;
	char			*content;
	struct s_buf	*next;
}	t_buf;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*get_next_line(int fd);

#endif

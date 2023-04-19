/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 01:36:06 by abenamar          #+#    #+#             */
/*   Updated: 2023/04/19 06:09:10 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef OPEN_MAX
#  define OPEN_MAX	FOPEN_MAX
# endif

# ifndef LINE_SIZE
#  define LINE_SIZE	4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	4096
# endif

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*get_next_line(int fd);

#endif

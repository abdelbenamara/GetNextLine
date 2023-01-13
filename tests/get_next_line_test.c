/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 03:05:39 by abenamar          #+#    #+#             */
/*   Updated: 2023/01/13 04:11:51 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_test.h"

void	get_next_line_test(const char *filename)
{
	int		fd;
	char	*s;

	printf(RESET "\n%s\t", filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(1);
	s = get_next_line(fd);
	ft_assert(1, !strcmp(s, "Hello\n"));
	free(s);
	s = get_next_line(fd);
	ft_assert(2, !strcmp(s, " \n"));
	free(s);
	s = get_next_line(fd);
	ft_assert(3, !strcmp(s, "World\n"));
	free(s);
	s = get_next_line(fd);
	ft_assert(4, !strcmp(s, "!\n"));
	free(s);
	s = get_next_line(fd);
	ft_assert(5, !strcmp(s, "\n"));
	free(s);
	s = get_next_line(fd);
	ft_assert(6, !strcmp(s, "Hello World!\n"));
	free(s);
	s = get_next_line(fd);
	ft_assert(7, s == NULL);
	free(s);
	if (close(fd) < 0)
		exit(1);
}

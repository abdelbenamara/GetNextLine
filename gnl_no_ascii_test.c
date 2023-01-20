/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_no_ascii_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 02:36:46 by abenamar          #+#    #+#             */
/*   Updated: 2023/01/15 04:46:32 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_test.h"

void	gnl_no_ascii_test()
{
	const char	*filename = "files/no-ascii";
	const int	fd = open(filename, O_RDONLY);
	char		*s;

	printf(RESET "\n%s \t\t", filename);
	if (fd < 0)
		exit(1);
	s = get_next_line(fd);
	ft_assert(1, !strcmp(s, "€\n"));
	free(s);
	s = get_next_line(fd);
	ft_assert(2, !strcmp(s, "£\n"));
	free(s);
	s = get_next_line(fd);
	ft_assert(3, !strcmp(s, "©\n"));
	free(s);
	s = get_next_line(fd);
	ft_assert(4, !strcmp(s, "±\n"));
	free(s);
	s = get_next_line(fd);
	ft_assert(5, !strcmp(s, "¶\n"));
	free(s);
	s = get_next_line(fd);
	ft_assert(6, !strcmp(s, "¿\n"));
	free(s);
	s = get_next_line(fd);
	ft_assert(7, s == NULL);
	if (close(fd) < 0)
		exit(1);
}

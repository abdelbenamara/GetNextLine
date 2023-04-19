/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_vertical_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:00:43 by abenamar          #+#    #+#             */
/*   Updated: 2023/04/19 07:05:33 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_test.h"

void	gnl_vertical_test(void)
{
	const char	*filename = "files/vertical";
	const int	fd = open(filename, O_RDONLY);
	char		*s;

	printf(RESET "\n%s \t\t", filename);
	if (fd < 0)
		exit(1);
	s = get_next_line(fd);
	ft_assert(1, !strcmp(s, "\n"));
	while (s)
	{
		free(s);
		s = get_next_line(fd);
	}
	ft_assert(2, s == NULL);
	s = get_next_line(fd);
	ft_assert(3, s == NULL);
	if (close(fd) < 0)
		exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_simple_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:57:37 by abenamar          #+#    #+#             */
/*   Updated: 2023/04/19 07:04:55 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_test.h"

void	gnl_simple_test(void)
{
	const char	*filename = "files/simple";
	const int	fd = open(filename, O_RDONLY);
	char		*s;

	printf(RESET "\n%s \t\t", filename);
	if (fd < 0)
		exit(1);
	s = get_next_line(fd);
	ft_assert(1, !strcmp(s, "test\n"));
	free(s);
	s = get_next_line(fd);
	ft_assert(2, s == NULL);
	if (close(fd) < 0)
		exit(1);
}

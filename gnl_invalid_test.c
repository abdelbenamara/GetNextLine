/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_invalid_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:39:55 by abenamar          #+#    #+#             */
/*   Updated: 2023/04/19 07:04:45 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_test.h"

void	gnl_invalid_test(void)
{
	const char	*filename = "invalid";
	int			fd;
	char		*s;

	printf(RESET "\n%s \t\t", filename);
	fd = open("files/invalid_file_which_does_not_exist", O_RDONLY);
	s = get_next_line(fd);
	ft_assert(1, s == NULL);
	fd = -256;
	s = get_next_line(fd);
	ft_assert(2, s == NULL);
	fd = open("files/", O_RDONLY);
	s = get_next_line(fd);
	ft_assert(3, s == NULL);
}

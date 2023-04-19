/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_empty_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:58:37 by abenamar          #+#    #+#             */
/*   Updated: 2023/04/19 07:04:31 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_test.h"

void	gnl_empty_test(void)
{
	const char	*filename = "files/empty";
	const int	fd = open(filename, O_RDONLY);
	char		*s;

	printf(RESET "\n%s \t\t", filename);
	if (fd < 0)
		exit(1);
	s = get_next_line(fd);
	ft_assert(1, s == NULL);
	s = get_next_line(fd);
	ft_assert(2, s == NULL);
	if (close(fd) < 0)
		exit(1);
}

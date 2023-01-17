/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_invalid_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:39:55 by abenamar          #+#    #+#             */
/*   Updated: 2023/01/15 21:59:14 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_test.h"

void	gnl_invalid_test()
{
	const char	*filename = "files/invalid";
	const int	fd = open(filename, O_RDONLY);
	char		*s;

	printf(RESET "\n%s \t\t", filename);
	s = get_next_line(fd);
	ft_assert(1, s == NULL);
	s = get_next_line(-2);
	ft_assert(2, s == NULL);
}

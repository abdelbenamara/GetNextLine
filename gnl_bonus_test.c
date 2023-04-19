/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:13:13 by abenamar          #+#    #+#             */
/*   Updated: 2023/04/19 07:03:47 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_test.h"

void	gnl_bonus_test(void)
{
	const int	fd1 = open("files/bonus1", O_RDONLY);
	const int	fd2 = open("files/bonus2", O_RDONLY);
	const int	fd3 = open("files/bonus3", O_RDONLY);
	char		*s1;
	char		*s2;
	char		*s3;

	printf(RESET "\n%s \t\t", "files/bonus*");
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		exit(1);
	s1 = get_next_line(fd1);
	s2 = get_next_line(fd2);
	s3 = get_next_line(fd3);
	ft_assert(1, !strcmp(s1, "test-1\n") && !strcmp(s2, "Hello\n") && !strcmp(s3, "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n"));
	free(s1);
	free(s2);
	free(s3);
	s2 = get_next_line(fd2);
	s3 = get_next_line(fd3);
	s1 = get_next_line(fd1);
	ft_assert(2, !strcmp(s1, "test-2\n") && !strcmp(s2, "World\n") && !strcmp(s3, "Nam eget tristique urna.\n"));
	free(s1);
	free(s2);
	free(s3);
	s3 = get_next_line(fd3);
	s1 = get_next_line(fd1);
	s2 = get_next_line(fd2);
	ft_assert(3, s1 == NULL && !strcmp(s2, "from\n") && !strcmp(s3, "Vivamus ligula orci, mollis non dui sed, mattis venenatis nunc.\n"));
	free(s2);
	free(s3);
	s1 = get_next_line(fd1);
	s3 = get_next_line(fd3);
	s2 = get_next_line(fd2);
	ft_assert(4, s1 == NULL && !strcmp(s2, "Get Next Line!") && !strcmp(s3, "Nulla euismod accumsan est, a hendrerit augue malesuada et.\n"));
	free(s2);
	free(s3);
	s3 = get_next_line(fd3);
	s2 = get_next_line(fd2);
	s1 = get_next_line(fd1);
	ft_assert(5, s1 == NULL && s2 == NULL && !strcmp(s3, "Nullam eget euismod quam.\n"));
	free(s3);
	s2 = get_next_line(fd2);
	s1 = get_next_line(fd1);
	s3 = get_next_line(fd3);
	ft_assert(6, s1 == NULL && s2 == NULL && !strcmp(s3, "Ut vestibulum elit eu accumsan mollis.\n"));
	free(s3);
	s1 = get_next_line(fd1);
	s2 = get_next_line(fd2);
	s3 = get_next_line(fd3);
	ft_assert(7, s1 == NULL && s2 == NULL && s3 == NULL);
	if (close(fd1) < 0 || close(fd2) < 0 || close(fd3) < 0)
		exit(1);
}

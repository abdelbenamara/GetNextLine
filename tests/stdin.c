/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 02:53:46 by abenamar          #+#    #+#             */
/*   Updated: 2023/01/15 04:06:38 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_test.h"

int	main(void)
{
	char	*s;

	write(STDOUT_FILENO, "Type then press enter, type 'q' to exit :\n", 42);
	while (!s || strcmp(s, "q\n"))
	{
		free(s);
		write(STDOUT_FILENO, "<< ", 3);
		s = get_next_line(STDIN_FILENO);
		printf(">> %s", s);
	}
	free(s);
	printf("bye!\n");
	return (0);
}

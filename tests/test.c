/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:02:16 by abenamar          #+#    #+#             */
/*   Updated: 2023/01/15 04:45:23 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_test.h"

void	ft_assert(int index, int assertion)
{
	if (assertion)
		printf(BOLDGREEN "%d. OK\t", index);
	else
		printf(BOLDRED "%d. KO\t", index);
}

int	main(void)
{
	printf("\nProject: " BOLDMAGENTA "Get Next Line\n");
	printf(RESET "\n-\nPart 1: " BOLDMAGENTA "Mandatory\n");
	printf(BOLDCYAN "\nFile" RESET "\t\t\t" BOLDCYAN "Tests\n");
	gnl_wrong_test();
	gnl_empty_test();
	gnl_simple_test();
	gnl_multiple_test();
	gnl_no_ascii_test();
	gnl_horizontal_test();
	gnl_vertical_test();
#ifdef BONUS
	printf("\n" RESET "\n-\nPart 2: " BOLDMAGENTA "Bonus" RESET "\n");
	printf(BOLDCYAN "\nFile" RESET "\t\t\t" BOLDCYAN "Tests" RESET "\n");
#endif
	printf("\n" RESET "\n");
	return (0);
}

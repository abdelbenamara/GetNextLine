/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:02:16 by abenamar          #+#    #+#             */
/*   Updated: 2023/01/13 04:12:53 by abenamar         ###   ########.fr       */
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
	printf(BOLDCYAN "\nFiles" RESET "\t\t" BOLDCYAN "Tests\n");
	get_next_line_test("mandatory1.txt");
#ifdef BONUS
	printf("\n" RESET "\n-\nPart 2: " BOLDMAGENTA "Bonus" RESET "\n");
	printf(BOLDCYAN "\nFiles" RESET "\t" BOLDCYAN "Tests" RESET "\n");
#endif
	printf("\n" RESET "\n");
	return (0);
}

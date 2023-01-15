/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:59:02 by abenamar          #+#    #+#             */
/*   Updated: 2023/01/15 04:45:36 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_TEST_H
# define GET_NEXT_LINE_TEST_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "get_next_line.h"

# define RESET			"\033[0m"
# define BOLDRED		"\033[1m\033[31m"      /* Bold Red */
# define BOLDGREEN		"\033[1m\033[32m"      /* Bold Green */
# define BOLDMAGENTA	"\033[1m\033[35m"      /* Bold Magenta */
# define BOLDCYAN		"\033[1m\033[36m"      /* Bold Cyan */

void	ft_assert(int index, int assertion);

void	gnl_wrong_test(void);
void	gnl_empty_test(void);
void	gnl_simple_test(void);
void	gnl_multiple_test(void);
void	gnl_no_ascii_test(void);
void	gnl_horizontal_test(void);
void	gnl_vertical_test(void);

#endif

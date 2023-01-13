/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 01:38:05 by abenamar          #+#    #+#             */
/*   Updated: 2023/01/13 03:50:39 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s && ++len)
		++s;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*s = src;

	if (!dst || !size)
		return (ft_strlen(src));
	while (--size && *s)
	{
		*dst = *s;
		++dst;
		++s;
	}
	*dst = '\0';
	while (*s)
		++s;
	return (s - src);
}

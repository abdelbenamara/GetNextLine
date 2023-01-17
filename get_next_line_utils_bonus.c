/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:11:06 by abenamar          #+#    #+#             */
/*   Updated: 2023/01/17 19:21:56 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

t_list	*ft_lstnew(void *content)
{
	t_list	*item;

	item = malloc(sizeof(t_list));
	if (!item)
		return (NULL);
	item->content = content;
	item->next = NULL;
	return (item);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

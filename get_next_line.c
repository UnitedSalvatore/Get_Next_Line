/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 04:32:10 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/29 22:20:42 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

t_list	*get_elem(const int fd, t_list **list)
{
	t_list			*current;
	char			*buff[BUFF_SIZE + 1];

	current = *list;
	while (current)
	{
		if (current->content_size == fd)
			return (current);
		current = current->next;
	}

	if ((current = ft_lstnew()))
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*current;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);


	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 04:32:10 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/30 16:48:46 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static *t_list_fd	*read_file(const int fd, t_list *current)
{
	char	*buf[BUFF_SIZE + 1];
	char	*str;
	int		ret;

	while (!(ft_strchr(current->content, '\n')) || \
			(ret = read(fd, buf, BUFFSIZE)) > 0)
	{
		buf[ret] = '\0';
		if (current->content)
		{
			str = current->content;
			current->content = ft_strjoin(current->content, buf);
			ft_strdel(&str);
			if (current->content == NULL)
				return (NULL);
		}
		else
			current->content = ft_strdup(buf);
	}
	return (current);
}

static *t_list_fd	*get_current_fd(const int fd, t_list **list)
{
	t_list_fd	*current;

	current = *list;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	if ((current = malloc(sizeof(*current))) == NULL)
		return (NULL);
	current->fd = fd;
	current->content = NULL;
	current->next = *list;
	*list = current;
	return (current);
}

int					get_next_line(const int fd, char **line)
{
	static t_list_fd	*list;
	t_list_fd			*current;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if ((current = get_current_fd(fd, &list)) == NULL)
		return (-1);

	return (0);
}

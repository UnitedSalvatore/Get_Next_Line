/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 04:32:10 by ypikul            #+#    #+#             */
/*   Updated: 2017/12/14 20:30:22 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

static void			del_node(t_list_fd **list, t_list_fd *curr)
{
	t_list_fd	*buf;

	if (*list == curr)
		*list = (*list)->next;
	else
	{
		buf = *list;
		while (buf->next != curr)
			buf = buf->next;
		buf->next = buf->next->next;
	}
	if (curr->content)
		ft_strdel(&(curr->content));
	free(curr);
}

static int			get_line(t_list_fd *curr, char **line)
{
	char	*ptr;
	char	*buf;

	if (curr->size == 0)
		return (0);
	if (!(ptr = ft_memchr(curr->content, '\n', curr->size)))
	{
		*line = curr->content;
		curr->content = NULL;
	}
	else
	{
		MALLCHECK((*line = ft_memalloc(ptr - curr->content + 1)));
		ft_memcpy(*line, curr->content, ptr - curr->content);
		curr->size -= (++ptr - curr->content);
		buf = curr->content;
		MALLCHECK((curr->content = ft_memalloc(curr->size + 1)));
		ft_memcpy(curr->content, ptr, curr->size);
		ft_strdel(&buf);
	}
	return (1);
}

static t_list_fd	*read_file(const int fd, t_list_fd *current)
{
	char	buf[BUFF_SIZE + 1];
	char	*str;
	int		ret;

	while (!(ft_memchr(current->content, '\n', current->size)) \
			&& (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = current->content;
		if (!(current->content = malloc(current->size + ret + 1)))
		{
			ft_strdel(&str);
			return (NULL);
		}
		ft_memcpy(current->content, str, current->size);
		ft_memcpy(current->content + current->size, buf, ret + 1);
		current->size += ret;
		ft_strdel(&str);
	}
	return (current);
}

static t_list_fd	*get_current_fd(const int fd, t_list_fd **list)
{
	t_list_fd	*current;

	current = *list;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	if (!(current = malloc(sizeof(*current))))
		return (NULL);
	current->fd = fd;
	if (!(current->content = ft_strdup("\0")))
	{
		free(current);
		return (NULL);
	}
	current->size = 0;
	current->next = *list;
	*list = current;
	return (current);
}

int					get_next_line(const int fd, char **line)
{
	static t_list_fd	*list;
	t_list_fd			*current;
	int					ret;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!(current = get_current_fd(fd, &list)))
		return (-1);
	if (read(fd, "", 0) < 0 || !(read_file(fd, current)))
	{
		del_node(&list, current);
		return (-1);
	}
	if ((ret = get_line(current, line)) == -1)
		return (-1);
	if (current->size == 0 || !(current->content))
		del_node(&list, current);
	return ((ret > 0) ? 1 : 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 04:32:10 by ypikul            #+#    #+#             */
/*   Updated: 2017/12/04 12:31:05 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

static void			check_empty(const char fd, t_list_fd **list)
{
	t_list_fd	*prev;
	t_list_fd	*buf;

	buf = NULL;
	if ((*list)->fd = fd)
	{
		if (!((*list)->content) || *((*list)->content) == '\0')
		{
			buf = *list;
			*list = (*list)->next;
		}
	}
	else
	{
		prev = *list;
		buf = *list->next;
		while (buf)
		{
			if (!(buf->content) || *(buf->content) == '\0')
			{
				prev->next = buf->next;
				ft_strdel(&(buf->content);
				free(buf);
				buf == NULL;
			}
			else
			{
				prev = buf;
				buf = buf->next;
			}
		}
	}
}

static int			get_line(t_list_fd *curr, char **line)
{
	char	*ptr;
	char	*buf;

	if (curr->content && *(curr->content) != '\0')
	{
		if (!(ptr = ft_strchr(curr->content, '\n')))
		{
			if (!(*line = ft_strdup(curr->content)))
				return (-1);
			ft_strdel(&(curr->content));
		}
		else
		{
			if (!(*line = ft_strsub(curr->content, 0, ptr - curr->content)))
				return (-1);
			buf = curr->content;
			curr->content = ft_strdup(ptr + 1);
			ft_strdel(&buf);
			if (!(curr->content))
				return (-1);
		}
		return (1);
	}
	return (0);
}

static t_list_fd	*read_file(const int fd, t_list_fd *current)
{
	char	buf[BUFF_SIZE + 1];
	char	*str;
	int		ret;

	while (!(ft_strchr(current->content, '\n')) \
			&& (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = current->content;
		current->content = ft_strjoin(current->content, buf);
		ft_strdel(&str);
		if (!(current->content))
			return (NULL);
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
	current->next = *list;
	*list = current;
	return (current);
}

int					get_next_line(const int fd, char **line)
{
	static t_list_fd	*list;
	t_list_fd			*current;
	int					ret;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, "", 0) < 0)
		return (-1);
	if (!(current = get_current_fd(fd, &list)) || \
			!(read_file(fd, current)))
		return (-1);
	if ((ret = get_line(current, line)) == -1)
		return (-1);
	check_empty(fd, &list);
	return ((ret > 0) ? 1 : 0);
}

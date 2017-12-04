/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 04:35:01 by ypikul            #+#    #+#             */
/*   Updated: 2017/12/01 14:55:44 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 64

typedef struct			s_list_fd
{
	int					fd;
	char				*content;
	struct s_list_fd	*next;
}						t_list_fd;

int						get_next_line(const int fd, char **line);

#endif

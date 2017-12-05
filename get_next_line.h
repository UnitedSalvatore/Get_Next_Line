/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 04:35:01 by ypikul            #+#    #+#             */
/*   Updated: 2017/12/05 18:49:49 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 

# define MALLCHECK(ptr) if (!ptr) return (-1);

typedef struct			s_list_fd
{
	int					fd;
	char				*content;
	struct s_list_fd	*next;
}						t_list_fd;

int						get_next_line(const int fd, char **line);

#endif

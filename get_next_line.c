/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 04:32:10 by ypikul            #+#    #+#             */
/*   Updated: 2017/11/26 04:32:13 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*current;
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);

	return (0);
}
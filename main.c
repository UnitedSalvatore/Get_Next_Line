/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:44:42 by ypikul            #+#    #+#             */
/*   Updated: 2017/12/06 02:07:19 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (fd < 0)
			return (0);
		while (get_next_line(fd, &line) > 0)
		{
			printf("%s\n", line);
			ft_strdel(&line);
		}
		close(fd);
	}
	return (0);
}

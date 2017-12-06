/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 05:50:53 by ypikul            #+#    #+#             */
/*   Updated: 2017/12/06 06:41:52 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

static void	ft_puterr(const char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}

int			main(int ac, char **av)
{
	int		num_of_repeat;
	int		*files;
	char	*line;
	int		i;
	int		ret;

	if (ac < 3)
		ft_puterr("Usage: ./gnl-test <num-of-repeat> <file1..fileN>");
	if ((num_of_repeat = ft_atoi(av[1])) < 1)
		ft_puterr("Number of repetitions < 1");
	if ((files = ft_memalloc(sizeof(int) * ((ac - 2) + 1))))
	{
		i = 1;
		while (++i < ac)
			files[i - 2] = open(av[i], O_RDONLY);
		files[i - 2] = 0;
		while (num_of_repeat--)
		{
			i = 0;
			while (i < (ac - 2))
			{
				ret = get_next_line(files[i], &line);
				if (ret == 1)
				{
					ft_putendl(line);
					ft_strdel(&line);
				}
				else if (ret == 0)
				{
					ft_putstr("The end of the file was reached: ");
					ft_putendl(av[i + 2]);
				}
				else if (ret == -1)
				{
					ft_putstr_fd("Error while reading file: ", STDERR_FILENO);
					ft_putendl_fd(av[i + 2], STDERR_FILENO);
				}
				i++;
			}
		}
		return (0);
	}
	return (1);
}

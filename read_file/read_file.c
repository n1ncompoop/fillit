/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 22:40:00 by pnarayan          #+#    #+#             */
/*   Updated: 2018/03/21 22:57:35 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define BUFSIZE 20

int		read_file(char *filename)
{
	int		fd;
	int		ret;
	char	buff[BUFFSIZE + 1];
	char	*full_str;
	
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	while (ret = read(fd, buff, BUFFSIZE))
	{
		if (ret == (int)'\n')
		{
			buff[ret] = '\0';
			ft_putstr(buff);
		}
		else
			return (0);
	}
	close(fd);
	return (1);
}

int		main(int argc, char **argv)
{
	int		ret;

	if (argc == 1)
	{
		ft_putstr("Usage method\n");
	}
	else if (argc == 2)
	{
		ret = read_file(argv[1]);
		printf("%d", ret);
	}
	return (0);
}

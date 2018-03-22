/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 22:40:00 by pnarayan          #+#    #+#             */
/*   Updated: 2018/03/22 00:47:36 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fillit.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define BUFFSIZE 21

int		read_file(char *filename)
{
	int		fd;
	int		ret;
	char	buff[BUFFSIZE + 1];
	char	*full_str;
	char	piece_2d[4][4];
	int		tet_id;
	
	tet_id = 1;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	while ((ret = read(fd, buff, BUFFSIZE)))
	{
		// if ret is less than BUFFSIZE it's invalid
		if (ret < BUFFSIZE) 
		{
			printf("Invalid maps");
			return (0);
		}
		buff[ret] = '\0';
		strncpy(full_str, buff, ret);
		//printf("full_str : \n%s",full_str); 
		conv_2d(full_str, tet_id);
		printf("\nend of map : %d\n", tet_id);
		tet_id++;
	}
	close(fd);
	return (1);
}

int		main(int argc, char **argv)
{
	int		ret;

	if (argc == 1)
	{
		printf("%s\n", "Usage Method");
//		ft_putstr("Usage method\n");
	}
	else if (argc == 2)
	{
		ret = read_file(argv[1]);
	}
	return (0);
}

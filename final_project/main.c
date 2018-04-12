/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 05:47:09 by pnarayan          #+#    #+#             */
/*   Updated: 2018/04/05 09:34:59 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_file(char *filename)
{
	int		fd;
	int		ret;
	char	buff[BUFFSIZE + 1];
	char	*full_str;
	int		tet_id;

	tet_id = 1;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	while ((ret = read(fd, buff, BUFFSIZE)))
	{
		if (ret > 545)
		{
			printf("Invalid maps");
			return (0);
		}
		if ((full_str = (char *)malloc(ret)) != NULL)
			strncpy(full_str, buff, ret);
		//printf("full_str : \n%s",full_str);
	}
	divide_pieces(full_str);
	close(fd);
	return (1);
}

int		main(int argc, char **argv)
{
	int		ret;

	if (argc == 1)
	{
		//printf("%s\n", "Usage Method");
		ft_putstr("Usage method\n");
	}
	else if (argc == 2)
	{
		ret = read_file(argv[1]);
	}
	return (0);
}

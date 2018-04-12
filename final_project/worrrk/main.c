/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 22:47:36 by pnarayan          #+#    #+#             */
/*   Updated: 2018/04/12 16:07:15 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_file(char *filename)
{
	int		fd;
	int		ret;
	char	buff[BUFFSIZE + 1];
	char	*full_str;
//	t_tetris	**allpieces;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	while ((ret = read(fd, buff, BUFFSIZE)))
	{
		if (ret > 545)
			return (0);
		//printf("Value of ret = %d\n", ret);
		if ((full_str = (char *)malloc(ret + 1)) != NULL)
			strncpy(full_str, buff, ret);
		full_str[ret] = '\0';
		//printf("full_str len : %lu\n",strlen(full_str));
	}
	close(fd);
	if (divide_pieces(full_str))
	{
		//display_list(allpieces);
		//solve_tetris(**tetris_list);
		return (1);
	}
	else
		return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("Usage method\n");
	else if (argc == 2)
	{
		if (read_file(argv[1]))
		{
			printf("Yay\n");
		}
		else
			printf("Error\n");
	}
	return (0);
}

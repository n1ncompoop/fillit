/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 22:40:00 by pnarayan          #+#    #+#             */
/*   Updated: 2018/03/23 05:03:17 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define BUFFSIZE 21

void	extract_tet(char **arr, int tet_id)
{
	int			x;
	int			i;
	int			j;
	int			coords[4][2];

	i = 0;
	x = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] == '#')
			{
				coords[x][0] = i;
				coords[x][1] = j;
				printf("%c ", tet_id + 'A' - 1);
				//printf("\t(%d%d)\t", i, j);
				x++;
			}
			else
				printf("  ");
			j++;
		}
		printf("\n");
		i++;
	}
	
	/*x = 0;
	while (x < 4)
	{
		//printf("(%d, %d)\t", coords[x][0], coords[x][1]);
		x++;
	}*/
}

void	conv_2d(char *str, int tet_id)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		arr[i] = (char *)malloc(1 * 5);
		j = 0;
		while (j < 5)
		{
			arr[i][j] = *str;
			//printf(" %c", arr[i][j]);
			j++;
			str++;
		}
		i++;
	}
	//valid_piece(arr, 0, 0);
	extract_tet(arr, tet_id);
}


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
		printf("\nMap : %d\n", tet_id);
		conv_2d(full_str, tet_id);
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

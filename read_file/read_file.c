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

int     valid_shape(char **str)
{
    int     connect;
	int		x;
	int		y;

	x = 0;
	y = 0;
    connect = 0;
    while (y < 4)
    {
		x = 0;
        while (x < 4)
        {
            if (str[y][x] == '#')
            {
				if (y != 3)
                	if (str[y + 1][x] == '#')
                    	connect++;
				if (x != 3)
                	if (str[y][x + 1] == '#')
                    	connect++;
            }
            x++;
        }
        y++;
    }
    if (connect > 2)
        return(1);
    else
        return(0);
}

int     valid_piece(char **str)
{
    int     shrp_cnt;
	int		x;
	int		y;

    shrp_cnt = 0;
	x = 0;
	y = 0;
	
    while (y < 4)
    {
		x = 0;
    	while (x < 4)            
		{
            if (str[y][x] == '.')
                x++;
            else if (str[y][x] == '#')
            {
        		x++;
                shrp_cnt++;
            }   
            else
                return (0);           
        }
        if (str[y][x] == '\n')
            y++;
        else
            return (0);
	}
    if ((shrp_cnt == 4) && valid_shape(str))
    		return (1);
    return (0);
}

int		*extract_tet(char **arr, int tet_id)
{
	int			x;
	int			i;
	int			j;
	int			coords[21];

	i = 0;
	x = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] == '#')
			{
				coords[x] = i;
				x++;
				coords[x] = j;
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
	
	x = 0;
	i = coords[0];
	j = coords[1];
	while (x < 8)
	{
		coords[x] -= i;
		printf("%d ", coords[x]);
		x++;
		coords[x] -= j;
		printf("%d ", coords[x]);
		x++;
	}
	return(coords);
}

int		*conv_2d(char *str, int tet_id)
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
	if (valid_piece(arr))
		return(extract_tet(arr, tet_id));
	return(0);
}


int		read_file(char *filename)
{
	int		fd;
	int		ret;
	char	buff[BUFFSIZE + 1];
	char	*full_str;
	char	piece_2d[4][4];
	int		tet_id;
	int		*onepce;
	
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
		ft_ralloc(onepce, conv_2d(full_str, tet_id)); 
		//realloc everytime 8 int and add in oncepce
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
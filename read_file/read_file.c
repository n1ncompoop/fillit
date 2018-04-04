/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 22:40:00 by pnarayan          #+#    #+#             */
/*   Updated: 2018/03/30 22:36:14 by rkwon            ###   ########.fr       */
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
int square_root(int n)
{
    int i;
    int result;
    
    i = 1;
    result = 1;
    if (n == 0 || n == 1)
        return (n);
    while (result < n)
    {
       if (result == n)
          return (result);
       i++;
       result = i * i;
    }
    return (i + 1);
}

char	**place_tet(char **board, int *piece, int *pce_ptr, int *y, int *x)//takes board[y][x] position and places tetris piece[*pce_ptr]
{
    int     *tmp;
    char    **tmp_board;
	int		i;

	i = 0;
    tmp_board = board;
    tmp = pce_ptr;
    if (board[*y][*x] == '.')
        board[*y][*x] = 'A' + piece[*tmp + 6];
	while (i < 3)
	{
        if (board[(*y) + piece[*pce_ptr]][(*x) + piece[*pce_ptr + 1]] == '.')
        {
		    board[(*y) + piece[i + 0]][(*x) + piece[i + 1]] = ('A' + piece[*tmp + 6]);
            *pce_ptr += 2;
        }
        else
        {
            board = tmp_board;//free tmp_board
            return(NULL);
        }
		i++;
	}
    return(board);
}

//PLACE TET FUNCTION

void	solve_tet(int *onepce, int *pce_place, char **map, int map_sz)
{
    int     i;
    int     *x;
    int     *y;
    int     tmp[7];

    i = 0;
    x = 0;
    y = 0;
    while (*y < map_sz)
    {
        while (*x < map_sz)
        {
            if (map[*y][*x] == '.')
            {
                if (!(map = place_tet(map, onepce, pce_place, y, x))) // will place until last piece
                {
                    if ((onepce[*(pce_place + 7)]) != -42) //IF THERE IS A NEXT PIECE
                    {
                        while (i < 7) //SWAP current piece with next piece
                        {
                            tmp[i] = onepce[*pce_place];
                            onepce[*pce_place] = onepce[*(pce_place + 7)];
                            onepce[*(pce_place + 7)] = tmp[i];
                            (*pce_place)++;
                            i++;
                        }
                        *pce_place = *(pce_place - 7);
                        map = solve_tet(onepce, pce_place, map, map_sz);
                    }
                    else
                        return(NULL);
                }
            }
            (*x)++;
        }
        x = 0;
        (*y)++;
    }
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*str;
	unsigned char	chr;

	i = 0;
	str = (char *)b;
	chr = (unsigned char)c;
	while (i < len)
	{
		str[i] = chr;
		i++;
	}
	return (str);
}

char    **gen_map(int x)//MEMORY GENERATION
{
    int     i;
    int     j;
    char     **map;

    i = 0;
    j = 0;
    if (!(map = (char **)malloc(sizeof(char *) * (x + 1))))
        return (NULL);
    while (i < x)
    {
        if (!(map[i] = (char *)malloc(sizeof(char) * (x + 1))))
            return (NULL);
        ft_memset(map[i], '.', x);
        map[i][x] = '\0';
        i++;
    }
    map[i] = NULL;
    return(map);
}

int     valid_shape(char **str)//VALIDITY
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

int     valid_piece(char **str) // VALIDITY
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

int		*extract_tet(char **arr, int tet_id)//returns one piece as int *
{
	int			x;
	int			i;
	int			j;
	static int	coords[23];

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
	coords[x] = tet_id;
	coords[x + 1] = -42;
	return(coords);
}

int		*conv_2d(char *str, int tet_id)//CHECK VALID THEN SENDS ONE TETRIS as int *
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
		return(extract_tet(arr, tet_id));/////////////////////////////one string of coord[21] --> to connect
	return(0);
}

int		*app_end(int *pce_lst, int *new_pce)//APPENDS NEXT PIECE TO CURRENT CHAIN OF PIECES
{
	int		cur_cnt;
	int		*new_lst;
	int		i;
	int		j;

	cur_cnt = 0;
	i = 0;
	j = 2;
	if ((pce_lst[cur_cnt]) != -42)
	{
		while (pce_lst[cur_cnt] != -42)
			cur_cnt++;
	}
	if (!(new_lst = (int *)malloc(sizeof(int) * (cur_cnt + 8))))
		return(NULL);
	while (pce_lst[i] != -42)
	{
		new_lst[i] = pce_lst[i];
		i++;
	}
	while (j < 9)
	{
		new_lst[i] = new_pce[j];
		i++;
		j++;
	}
	new_lst[i] = -42;
	return(new_lst);
}

//void	solve_tet(char **map, int *onepce, int minmapsize)
int		read_file(char *filename)//CONTROLLER
{
	int		fd;
	int		ret;
	char	buff[BUFFSIZE + 1];
	char	*full_str;
	char	piece_2d[4][4];
	int		tet_id;
	int		*onepce;
	char	**map;
	int		map_sz;

	tet_id = 1;
	onepce[0] = -42;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return(0);
	while ((ret = read(fd, buff, BUFFSIZE)))
	{
		// if ret is less than BUFFSIZE it's invalid
		if (ret < BUFFSIZE) 
		{
			printf("Invalid maps");
			return(0);
		}
		buff[ret] = '\0';
		strncpy(full_str, buff, ret); //FIX MUST FIX MUST FIX MUST FIX MUST
		//printf("full_str : \n%s",full_str); 
		printf("\nMap : %d\n", tet_id);
		onepce = app_end(onepce, conv_2d(full_str, tet_id)); // recieve full list of coords (no 0,0 in list because it's already assumed) // tet_id = last number
		tet_id++;
	}
	/*tet_id = 0;
	printf("\n");
	while (onepce[tet_id] != -42)
	{
		printf("%d", onepce[tet_id]);
		tet_id++;
	}*/
	map_sz = square_root(tet_id * 4); //min map size
    map = gen_map(map_sz);

	if (!(solve_tet(&onepce, pce_place, map, map_sz)))
	{
		map = gen_map(map_sz++);
		solve_tet(&onepce, pce_place, map, map_sz);
	}
		
	close(fd);
	return(1);
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
	return(0);
}

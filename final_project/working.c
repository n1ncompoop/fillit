/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 22:40:00 by pnarayan          #+#    #+#             */
/*   Updated: 2018/04/06 01:43:06 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../libft/libft.h"
#define BUFFSIZE 546

typedef struct		s_tetris
{
	char			tet_id;
	int				*pieces;
	struct s_tetris	*next;
}					t_tetris;

t_tetris	*ft_create_piece(int *co)
{
	t_tetris *tet_piece;

	tet_piece = NULL;
	tet_piece = (t_tetris *)malloc(sizeof(t_tetris));
	if (tet_piece)
	{
		tet_piece->pieces = co;
		tet_piece->next = NULL;
	}
	return (tet_piece);
}

void	ft_add_piece(t_tetris **tetris, int *co)
{
	t_tetris *piece;

	piece = *tetris;
	if (piece != NULL)
	{
		while (piece->next != NULL)
			piece = piece->next;
		piece->next = ft_create_piece(co);
	}
	else
		*tetris = ft_create_piece(co);
}

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

void	map_coords(int *coords, int tet_id)
{
	int		x;
	int		k;
	int		id;
	int		i;
	int		j;
	int		**all_pieces;

	all_pieces = (int **)malloc(sizeof(int *) * tet_id);
	k = 0;
	id = tet_id - 1;
	all_pieces[id] = (int *)malloc(sizeof(int) * 9);
	x = 0;
	i = coords[0];
	j = coords[1];
	while (x < 8)
	{
		all_pieces[id][k++] = coords[x] - i;
		//coords[x] = coords[x] - i;
		//ft_putnbr(all_pieces[id][k - 1]);
		x++;
		all_pieces[id][k++] = coords[x] - j;
		//coords[x] = coords[x] - j;
		//ft_putnbr(all_pieces[id][k - 1]);
		x++;
	}
	all_pieces[id][k] = tet_id;
	//coords[x] = tet_id;
	//ft_putnbr(all_pieces[id][k]);
	//ft_putchar('\n');
}

void	extract_tet(char **arr, int tet_id)
{
	int			x;
	int			i;
	int			j;
	int			coords[8];

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
				coords[x++] = j;
			}
			else
				printf("  ");
			j++;
		}
		i++;
	}
	map_coords(coords, tet_id);
}

void	conv_2d(char *str, int tet_id)
{
	char	**arr;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	arr = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		arr[i] = (char *)malloc(1 * 5);
		j = 0;
		while (j < 5)
			arr[i][j++] = str[k++];
		//printf(" %c", arr[i][j]);
		i++;
	}
	if (valid_piece(arr))
		extract_tet(arr, tet_id);
}

void	divide_pieces(char *f_str)
{
	char	*piece_str;
	int		tet_id;
	int		i;
	int		j;
	int		mod;

	tet_id = 1;
	i = 0;
	j = 0;
	mod = 20;
	piece_str = (char *)malloc(sizeof(char) * 21);
	while (f_str[i])
	{
		// Calls convert 2D after two '\n' (check for two newlines)
		if (i > 0 && f_str[i - 1] == '\n')
		{
			// works on both condition with '\n\n' and '\n'
			if (i % mod == 0 || f_str[i] == '\n')
			{
				//ft_putstr(piece_str);
				conv_2d(piece_str, tet_id);
				tet_id++;
				mod = mod + 21;
				// skips the newline being copied as the first character
				i++;
				j = 0;
			}
		}
		//if (j < 20)
		piece_str[j++] = f_str[i++];
	}
}

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
		printf("%s\n", "Usage Method");
		//		ft_putstr("Usage method\n");
	}
	else if (argc == 2)
	{
		ret = read_file(argv[1]);
	}
	return (0);
}

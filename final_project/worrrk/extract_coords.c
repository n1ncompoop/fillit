/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 01:19:55 by pnarayan          #+#    #+#             */
/*   Updated: 2018/04/12 16:30:08 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_in_struct(int	*coords, int tet_id)
{
	t_tetris	*one_piece;
	int			co;
	int			i;
	int			x;
	int			y;

	co = 0;
	i = 0;
	x = coords[0];
	y = coords[1];
	one_piece = (t_tetris *)ft_memalloc(sizeof(t_tetris));
	ft_bzero(one_piece, sizeof(t_tetris));
	while (co < 8)
	{
		one_piece->pieces[i++] = coords[co++] - x;
		one_piece->pieces[i++] = coords[co++] - y;
	}
	one_piece->tet_id = tet_id + 'A' - 1;
	/*printf("%c\t", one_piece->tet_id);
	i = 0;
	while (i < 8)
		printf("%d", one_piece->pieces[i++]);
	printf("\n");*/
	//ft_add_piece(coords, x, y, tet_id); 
}

void	extract_tet(char **arr, int tet_id)
{
	t_tetris	*one_piece;
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
				coords[x++] = i;
				coords[x++] = j;
			}
			j++;
		}
		i++;
	}
	//fill_in_struct(coords, tet_id);
	one_piece = NULL;
	//one_piece = (t_tetris *)ft_memalloc(sizeof(t_tetris));
	ft_add_piece(&one_piece, coords, coords[0], coords[1], tet_id); 
	//display_list(one_piece);
}

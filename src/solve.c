/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 21:09:51 by pnarayan          #+#    #+#             */
/*   Updated: 2018/04/25 21:09:59 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

/*
** Backtracking algorithm to solve tetris
*/

int		solve_tet(t_map *map, t_tetris **tetlist)
{
	t_point		point;
	t_tetris	*curr;

	point.x = 0;
	curr = *tetlist;
	if (curr == NULL)
		return (1);
	while (point.x < map->size)
	{
		point.y = 0;
		while (point.y < map->size)
		{
			if (place_if_valid(point, map, curr))
			{
				if (solve_tet(map, &(curr->next)))
					return (1);
				else
					fill_map(curr, map, point, '.');
			}
			point.y++;
		}
		point.x++;
	}
	return (0);
}

/*
** Checks if the map has enough space to place the current tetromino
*/

int		place_if_valid(t_point point, t_map *map, t_tetris *curr)
{
	int	dot_cnt;
	int	i;
	int	ii;
	int	jj;

	dot_cnt = 0;
	i = 0;
	while (i < 7)
	{
		ii = point.x + curr->pieces[i];
		jj = point.y + curr->pieces[i + 1];
		if (ii >= map->size || jj >= map->size)
			return (0);
		else if (map->map[ii][jj] == '.')
		{
			i += 2;
			dot_cnt++;
		}
		else
			return (0);
	}
	if (!(dot_cnt == 4))
		return (0);
	fill_map(curr, map, point, curr->tet_id);
	return (1);
}

/*
** Clears or sets the map based on the char. Pass curr->tet_id if the tetromino
** can be placed else pass '.' to clear the map
*/

void	fill_map(t_tetris *curr, t_map *map, t_point point, char c)
{
	int	i;
	int	ii;
	int	jj;

	i = 0;
	while (i < 7)
	{
		ii = point.x + curr->pieces[i];
		jj = point.y + curr->pieces[i + 1];
		map->map[ii][jj] = c;
		i += 2;
	}
}

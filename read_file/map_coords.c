/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 05:51:11 by pnarayan          #+#    #+#             */
/*   Updated: 2018/03/25 05:54:09 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

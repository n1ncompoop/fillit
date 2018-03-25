/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_tet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 03:54:50 by pnarayan          #+#    #+#             */
/*   Updated: 2018/03/25 05:46:15 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

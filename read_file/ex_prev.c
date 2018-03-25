/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_tet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 03:54:50 by pnarayan          #+#    #+#             */
/*   Updated: 2018/03/22 04:51:57 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	extract_tet(char **tet_2d, int tet_id)
{
	int			i;
	int 		j;
	int			x;
	int			y;
	t_piece		*tet_m;

	i = 0;
	x = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			y = 0;
			if (tet_2d[i][j] == '#')
			{
				tet_m->coords[x][y] = i;
				tet_m->coords[x][y + 1] = j;
				x++;
			}
			j++;
		}
		i++;
	}
	
	x = 0;
	while (x < 4)
	{
		y = 0;
		printf("(%d, %d)\t", tet_m->coords[x][y], tet_m->coords[x][y + 1]);
		x++;
	}

}

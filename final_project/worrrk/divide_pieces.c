/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 00:32:37 by pnarayan          #+#    #+#             */
/*   Updated: 2018/04/11 04:21:25 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		conv_2d(char *str, int tet_id)
{
	char	**arr;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	//printf("The piece_id is %d\n", tet_id);
	arr = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
	{
		arr[i] = (char *)malloc(5);
		j = 0;
		while (j < 5)
			arr[i][j++] = str[k++];
		i++;
	}
	if (valid_piece(arr))
	{
		//printf("Valid piece %d\n", tet_id);
		extract_tet(arr, tet_id);
		return (1);
	}
	else
		//printf("isn't a valid piece %d\n", tet_id);
		return (0);
}

int		div_conv(char *tet_str, int tet_id)
{
	int		good;
	int		mod;

	mod = 20;
	good = 0;
	//ft_putstr(tet_str);
	if (!conv_2d(tet_str, tet_id))
		return (0);
	return (1);
}

int		divide_pieces(char *f_str)
{
	char	*piece_str;
	int		good;
	int		tet_id;
	size_t	i;
	int		j;

	i = 0;
	tet_id = 0;
	good = 1;
	piece_str = (char *)ft_memalloc(21);
	if (!valid_newlines(f_str))
		return (0);
	while (i < ft_strlen(f_str))
	{
		ft_bzero(piece_str, ft_strlen(piece_str));
		j = 0;
		while (j < 20)
			piece_str[j++] = f_str[i++];
		piece_str[j] = '\0';
		tet_id++;
		i++;
		//ft_putstr(piece_str);
		if (!div_conv(piece_str, tet_id))
		{
			good = 0;
			break ;
		}
	}
	if (!good)
		return (0);
	return (1);
}

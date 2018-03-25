/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 04:52:16 by pnarayan          #+#    #+#             */
/*   Updated: 2018/03/25 05:49:18 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:52:40 by pnarayan          #+#    #+#             */
/*   Updated: 2018/04/12 15:48:23 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#define BUFFSIZE 546

typedef struct		s_tetris
{
	char			tet_id;
	int				pieces[8];
	struct s_tetris	*next;
}					t_tetris;

/*
 * List of tetris
 */
void				display_list(t_tetris **tetris);
t_tetris			*ft_create_piece(int *co, int x, int y, int tet_id);
void				ft_add_piece(t_tetris **tetris, int *co, int x, int y, int tet_id);

/*
 * Validity
 */
int		valid_newlines(char *str);
int     valid_shape(char **str);
int     valid_piece(char **str);

/*
 * Extracting
 */
int		conv_2d(char *str, int tet_id);
int		divide_pieces(char *f_str);
int		div_conv(char *tet_str, int tet_id);
void	extract_tet(char **arr, int tet_id);
int		read_file(char *filename);
void	fill_in_struct(int	*coords, int tet_id);

#endif

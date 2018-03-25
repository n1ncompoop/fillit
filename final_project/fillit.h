/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkwon <rkwon@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 21:06:41 by rkwon             #+#    #+#             */
/*   Updated: 2018/03/25 06:03:22 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
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
	int				*pieces;
	struct s_tetris	*next;
}					t_tetris;

int					read_file(char *filename);
void				conv_2d(char *str, int tet_id);
void				divide_pieces(char *f_str);
void				extract_tet(char **arr, int tet_id);
void				map_coords(int *coords, int tet_id);
t_tetris			*ft_create_piece(int *co);
void				ft_add_piece(t_tetris **tetris, int *co);
int     			valid_shape(char **str);
int     			valid_piece(char **str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkwon <[rkwon@student.42.us.org]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 21:06:41 by rkwon             #+#    #+#             */
/*   Updated: 2018/03/19 21:06:42 by rkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct      s_piece
{
    char            **name;
    int             width;
    int             height;
    char            letter;
    struct s_piece  *next;
}                   t_piece;
3
#endif
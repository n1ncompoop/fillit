/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:59:19 by pnarayan          #+#    #+#             */
/*   Updated: 2018/03/21 22:21:42 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	fill_ctrl(char *filename)
{
	/*
	 * No of maps
	 */
	int			no_maps;
	t_piece		*tet_pce;	
	char		**tet_lst;

/*	if (tet_pce = (t_piece*)ft_memalloc(sizeof(t_piece)) == NULL)
		return (NULL);
*/
	read_file(filename);

}

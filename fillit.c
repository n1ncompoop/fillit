/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:40:29 by pnarayan          #+#    #+#             */
/*   Updated: 2018/03/21 21:03:33 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("Usage method\n");
	}
	else if (argc == 2)
	{
		fill_ctrl(argv[1]);
	}
	return (0);
}

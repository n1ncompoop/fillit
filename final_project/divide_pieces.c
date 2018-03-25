/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_pieces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 05:46:30 by pnarayan          #+#    #+#             */
/*   Updated: 2018/03/25 05:53:36 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	divide_pieces(char *f_str)
{
	char	*piece_str;
	int		tet_id;
	int		i;
	int		j;
	int		mod;

	tet_id = 1;
	i = 0;
	j = 0;
	mod = 20;
	piece_str = (char *)malloc(sizeof(char) * 21);
	while (f_str[i])
	{
		// Calls convert 2D after two '\n' (check for two newlines)
		if (i > 0 && f_str[i - 1] == '\n')
		{
			// works on both condition with '\n\n' and '\n'
			if (i % mod == 0 || f_str[i] == '\n')
			{
				//ft_putstr(piece_str);
				conv_2d(piece_str, tet_id);
				tet_id++;
				mod = mod + 21;
				// skips the newline being copied as the first character
				i++;
				j = 0;
			}
		}
		//if (j < 20)
		piece_str[j++] = f_str[i++];
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkwon <rkwon@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:53:11 by rkwon             #+#    #+#             */
/*   Updated: 2018/03/15 15:53:23 by rkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int     valid_shape(char **str)
{
    int     connect;
	int		x;
	int		y;

	x = 0;
	y = 0;
    connect = 0;
    while (y < 4)
    {
		x = 0;
        while (x < 4)
        {
            if (str[y][x] == '#')
            {
				if (y != 3)
                	if (str[y + 1][x] == '#')
                    	connect++;
				if (x != 3)
                	if (str[y][x + 1] == '#')
                    	connect++;
            }
            x++;
        }
        y++;
    }
    if ((connect == 3) || (connect == 4))
        return(1);
    else
        return(0);
}

int     valid_piece(char **str)
{
    int     shrp_cnt;
	int		x;
	int		y;

    shrp_cnt = 0;
	x = 0;
	y = 0;
	
    while (y < 4)
    {
		x = 0;
    	while (x < 4)            
		{
            if (str[y][x] == '.')
                x++;
            else if (str[y][x] == '#')
            {
        		x++;
                shrp_cnt++;
            }   
            else
                return (0);           
        }
        if (str[y][x] == '\n')
            y++;
        else
            return (0);
	}
    if ((shrp_cnt == 4) && valid_shape(str))
    		return (1);
    return (0);
}

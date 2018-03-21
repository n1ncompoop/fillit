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

int     valid_piece(char **str, int x, int y)
{
    int     shrp_cnt;

    shrp_cnt = 0;
    while (str[y][x])
    {
        while (y < 4)
        {
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
            {
                x = 0;
                y++;
            }
            else
                return (0);
        }
        if (y == 4)
            if ((shrp_cnt == 4) && valid_shape(str, 0, 0) 
                && ((str[y][x] == '\n') || (str[y][x] == '\0')))
                return (1);
        else
            return (0);  
    }
}

int     valid_shape(char **str, int x, int y)
{
    int     connect;

    connect = 0;
    while (str[y][x])
    {
        while (y < 4)
        {
            while (x < 4)
            {
                if (str[y][x] == '#')
                {
                    if (str[y + 1][x] == '#')
                        connect++;
                    if (str[y][x + 1] == '#')
                        connect++;
                }
                x++;
            }
            y++;
        }
    }
    if (connect == 3)
        return(1);
    else
        return(0);
}
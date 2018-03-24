/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkwon <[rkwon@student.42.us.org]>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 02:48:27 by rkwon             #+#    #+#             */
/*   Updated: 2018/03/23 02:48:29 by rkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*str;
	unsigned char	chr;

	i = 0;
	str = (char *)b;
	chr = (unsigned char)c;
	while (i < len)
	{
		str[i] = chr;
		i++;
	}
	return (str);
}

int    **gen_map(int x)
{
    int     i;
    int     j;
    int     **map;

    i = 0;
    j = 0;
    if (!(map = (int **)malloc(sizeof(int *) * (x + 1))))
        return (NULL);
    while (i < x)
    {
        if (!(map[i] = (int *)malloc(sizeof(int) * (x + 1))))
            return (NULL);
        ft_memset(map[i], 0, x);
        map[i][x] = NULL;
        i++;
    }
    map[i] = NULL;
    return(map);
}

int main()
{
    int     **map;
    int     x;
    int     i;
    int     j;

    i = 0;
    j = 0;
    x = 9;
    map = gen_map(x);
    while (i < x)
    {
        while (j < x)
        {
            printf("%d ", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return (0);
}
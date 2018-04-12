/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnarayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:19:25 by pnarayan          #+#    #+#             */
/*   Updated: 2018/04/08 18:32:02 by pnarayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_attacked(int x, int y, int board[N][N], int N)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < x)
	{
		if (board[x][i])
			return false;
		i++;
	}

	i = x;
	j = y;
	while (i >= 0 && j >= 0)
	{
		if (board[i][j])
			return false;
		i--;
		j--;
	}

	i = x;
	j = y;
	while (j >= 0 && i < N)
	{
		if (board[i][j])
			return false;
		i++;
		j--;
	}

	return true;
}

int main()
{
	int num;

	scanf("%d", &num);
	printf("Input number is %d. \n", num);
	return (0);
}

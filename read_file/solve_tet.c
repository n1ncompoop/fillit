#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int square_root(int n)
{
    int i;
    int result;
    
    i = 1;
    result = 1;
    if (n == 0 || n == 1)
        return (n);
    while (result < n)
    {
       if (result == n)
          return (result);
       i++;
       result = i * i;
    }
    return (i + 1);
}

char	**place_tet(char **board, int *piece, int *pce_ptr, int *y, int *x)//takes board[y][x] position and places tetris piece[*pce_ptr]
{
    int     *tmp;
    char    **tmp_board;

    tmp_board = board;
    tmp = pce_ptr;
    if (board[*y][*x] == '.')
        board[*y][*x] = 'A' + piece[*tmp + 6];
	while (i < 7)
	{
        if (board[(*y) + piece[*pce_ptr]][(*x) + piece[*pce_ptr + 1]] == '.')
        {
		    board[(*y) + piece[i + 0]][(*x) + piece[i + 1]] = ('A' + piece[*tmp + 6]);
            *pce_ptr += 2;
        }
        else
        {
            board = tmp_board;//free tmp_board
            return(NULL);
        }
	}
    free_tmp
    return(board);
}

//PLACE TET FUNCTION

void	solve_tet(int *onepce, int *pce_place, char **map)
{
    char    **map;
    int     map_sz;
    int     i;
    int     *x;
    int     *y;
    int     tmp[7];

    i = 0;
    x = 0;
    y = 0;
    /*map_sz = square_root(tet_id * 4);
    map = gen_map(map_sz); */ //PUT OUTSIDE THIS FUNCTION
    while (*y < map_sz)
    {
        while (*x < map_sz)
        {
            if (map[*y][*x] == '.')
            {
                if (!(map = place_tet(map, onepce, *pce_place, &y, &x))) // will place until last piece
                {
                    if ((onepce[(*pce_place) + 7]) != -42) //IF THERE IS A NEXT PIECE
                    {
                        while (i < 7) //SWAP current piece with next piece
                        {
                            tmp[i] = onepce[*pce_place];
                            onepce[*pce_place] = onepce[(*pce_place) + 7];
                            onepce[(*pce_place) + 7] = tmp[i];
                            (*pce_place)++;
                            i++;
                        }
                        *pce_place -= 7;
                        map = solve_tet(onepce, *pce_place, map);
                    }
                    else
                        return(NULL);
                }
                else
                    map = place_tet(map, onepce, *pce_place, &y, &x);
            }
            (*x)++;
        }
        x = 0;
        (*y)++;
    }
}

#include <stdio.h>

int		*extract_tet(char **arr, int tet_id)
{
	int			x;
	int			i;
	int			j;
	int			coords[21];

	i = 0;
	x = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[i][j] == '#')
			{
				coords[x] = i;
				x++;
				coords[x] = j;
				printf("%c ", tet_id + 'A' - 1);
				//printf("\t(%d%d)\t", i, j);
				x++;
			}
			else
				printf("  ");
			j++;
		}
		printf("\n");
		i++;
	}
	
	x = 0;
	i = coords[0];
	j = coords[1];
	while (x < 8)
	{
		coords[x] -= i;
		printf("%d ", coords[x]);
		x++;
		coords[x] -= j;
		printf("%d ", coords[x]);
		x++;
	}
	return(coords);
}
#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"


void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	if (stable(grid1))
	{
		return;
	}

	while (!stable(grid1))
	{
		printf("=\n");
		print_grid2(grid1);
		stablise(grid1);
	}

}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_grid2(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}


int stable(int grid1[3][3])
{

	int is_stable = 1;

	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			if (grid1[i][j] >= 4)
			{
				is_stable = 0;
			}
		}
	}
	return is_stable;
}

void stablise(int grid1[3][3])
{
	int temp[3][3] = {0};

	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			if (grid1[i][j] >= 4)
			{
				temp[i][j] -= 4;

				if (i > 0) temp[i - 1][j]++;
				if (i < 2) temp[i + 1][j]++;
				if (j > 0) temp[i][j - 1]++;
				if (j < 2) temp[i][j + 1]++;
			}

		}
	}
	for (int i = 0; i < 3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			grid1[i][j] += temp[i][j];
		}
	}
}

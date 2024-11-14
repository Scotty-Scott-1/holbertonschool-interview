#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "menger.h"

int hole(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
		{
			return 1;
		}
		col /= 3;
		row /=3;
	}
	return 0;
}

void menger(int level) {

	if (level < 0) {
		return;
	}

	int size = (int)pow(3,level);

	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			if (hole(row, col))
			{
				printf(" ");
			} else {
				printf("#");
			}
		}
		printf("\n");
	}


}

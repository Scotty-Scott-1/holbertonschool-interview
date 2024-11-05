#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"


int slide_line(int *line, size_t size, int direction)
{
	int i;
	int j;
	int last_combined = -1;

	if (direction != 1 && direction != 0) {
		return 0;
	}

	if (direction == 0)
	{
		for(i = 0, j = 0; i < (int)size; i++)
		{
			if(line[i] != 0)
			{
				if(j > 0 && line[j - 1] == line[i] && last_combined != j - 1) {
					line[j - 1] *= 2;
					line[i] = 0;
					last_combined = j - 1;
				} else {
					if (j != i) {
						line[j] = line[i];
						line[i] = 0;
					}
					last_combined = -1;
					j++;
				}
			}
		}

	}

	if (direction == 1)
	{
		for(i = size - 1, j = size - 1; i >= 0; i--)
		{
			if(line[i] != 0)
			{
				if(j < (int)size - 1 && line[j + 1] == line[i] && last_combined != j + 1) {
					line[j + 1] *= 2;
					line[i] = 0;
					last_combined = j + 1;
				} else {
					if (j != i) {
						line[j] = line[i];
						line[i] = 0;
					}

					j--;
				}
			}
		}

	}
	return 1;

}

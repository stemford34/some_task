#include <stdio.h>

void sastantua(int size);

int recursive_heigth(int);
int width(int);
void doit(char** mass, int, int);

int main()
{
	sastantua(5);
}

void sastantua(int size)
{

}

void doit(int size)
{
	int col;
	int row;
	int sizeClone;
	int floor;

	floor = size;
	sizeClone = 0;
	row = recursive_heigth(size);
	col = width(size);
	int i;
	int j;
	char pir[row][col];

	printf("%d\n", col);
	i = 0;
	j = 0;
	while (i != row)
	{
		while (j != col)
		{
			pir[i][j] = ' ';
			++j;
		}
		j = 0;
		++i;
	}
	//------------------------------------------------------------------------------------------
	int et;
	int current;
	int pr;
	int prmain;
	int minus;

	minus = 2;
	pr = 3;
	prmain = 3;
	et = 1;
	current = col / 2 - 1;
	i = 0;
	j = 0;

	while (i < row)
	{
		while (j < col)
		{
			if (j  == current)
				pir[i][j] = '/';
			else if (j == col - current - 1)
				pir[i][j] = '\\';
			else if (j > current && j < col - current - 1)
				pir[i][j] = '*';
			++j;

		}
		--current;
		j = 0;
		--pr;
		if (pr == 0)
		{
			++prmain;
			pr = prmain;
			++et;
			if (et % 2 != 0)
			{
				++minus;
				current = current - minus + 1;
			}else{
				current = current - minus;
			}
		}
		++i;
	}
	//--------------------------------------------------------------------------------------------------------
	if (floor % 2 == 0)
	{
		i = row - floor + 1;
		j = col / 2 - floor / 2 + 1;
		while (i < row)
		{
			while (j != col / 2 + (floor + 1) / 2)
			{
				if ( i == row - ((floor + 1) / 2) && j == (col / 2 + (floor + 1) / 2) - 2)
					pir[i][j] = '$';
				else
					pir[i][j] = '|';
				++j;
			}
			j = col / 2 - floor / 2 + 1;
			++i;
		}
	}
	else
	{
		i = row - floor;
		j = col / 2 - floor / 2;
		while (i < row)
		{
			while (j != col / 2 + (floor + 1) / 2)
			{
				if ( i == row - ((floor + 1) / 2) && j == (col / 2 + (floor + 1) / 2) - 2)
					pir[i][j] = '$';
				else
					pir[i][j] = '|';
				++j;
			}
			j = col / 2 - floor / 2;
			++i;
		}
	}
//------------------------------------------------------------------------------------------------------------


}

int recursive_heigth(int floor)
{
	if (floor > 1)
	{
		return (recursive_heigth(floor - 1) + 3 + floor - 1);
	}
	else if (floor == 1)
	{
		return (3);
	}
	else
	{
		return (0);
	}
}

int width(int floor)
{
	int i;
	int current;
	int width;

	i = 2;
	current = 2;
	width = 5;
	while (current <= floor)
	{
		if (current % 2 == 0)
		{
			++i;
			width = width + i * 2 + (current + 1) * 2;
		}
		else
		{
			width = width + i * 2 + (current + 1) * 2;
		}
		++current;
	}
	return (width + 2);
}

void print(char **pir, int row, int col)
{
	int i;
	int j;

	i = 0;
	j = 0;
		while (i != row)
	{
		while (j != col)
		{
			printf("%c", pir[i][j]);
			++j;
		}
		printf("%c\n", ' ');
		j = 0;
		++i;
	}
}





















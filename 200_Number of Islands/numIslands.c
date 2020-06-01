#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define true 1
#define false 0
#define bool int
//直接修改grid，将已访问过的岛屿值设为0，避免重复计数
bool DFS(char** grid, int gridSize, int* gridColSize, int x, int y)
{
	if (x < 0 || x >= gridSize || y < 0 || y >= gridColSize[0]  || grid[x][y] == '0')
		return false;
	else
	{
		grid[x][y] = '0';
		DFS(grid, gridSize, gridColSize, x - 1, y );
		DFS(grid, gridSize, gridColSize, x + 1, y);
		DFS(grid, gridSize, gridColSize, x, y - 1);
		DFS(grid, gridSize, gridColSize, x, y + 1);
		return true;
	}
	
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
	if (grid == NULL || gridColSize==NULL || gridSize <= 0 || gridColSize[0] <= 0)
		return 0;
	int row, col, num=0;
	for (row = 0; row < gridSize; row++) {
		for (col = 0; col < gridColSize[0]; col++){
			if (DFS(grid, gridSize, gridColSize, row , col))
			{
				num++;
				grid[row][col] = '0';
			}
		}
	}
	return num;
}

void main()
{

char grid[4][5] = { "11000","11000","00100","00011" };
int colSize = 5;
char* p[4];
for (int i = 0; i < 4; i++)
	p[i] = &grid[i];

int res = numIslands(p, 4, &colSize);
}

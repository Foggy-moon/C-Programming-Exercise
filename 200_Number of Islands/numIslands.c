#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define true 1
#define false 0
#define bool int
bool dfs(char** grid, int gridSize, int* gridColSize, int row, int col, int** visit)
{
	if (row < 0 || row >= gridSize || col < 0 || col >= *gridColSize)
		return false;
	if (grid[row][col] == '1' && visit[row][col] == 0)
	{
		visit[row][col] = 1;
		dfs(grid, gridSize, gridColSize, row + 1, col, visit);
		dfs(grid, gridSize, gridColSize, row - 1, col, visit);
		dfs(grid, gridSize, gridColSize, row, col + 1, visit);
		dfs(grid, gridSize, gridColSize, row, col - 1, visit);
		return true;
	}
	return false;
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
	int i, row, col, nums = 0;
	if (grid == NULL || gridSize <= 0 || gridColSize == NULL || *gridColSize <= 0)
		return 0;
	//���յ�ͼ��С�����ѷ��������ַ����ʼÿ��λ��δ����
	int** visit = (int**)malloc(sizeof(int*) * gridSize);
	for (i = 0; i < gridSize; i++)
	{
		visit[i] = (int*)malloc(sizeof(int) * (*gridColSize));
		memset(visit[i], 0, sizeof(int) * (*gridColSize));
	}
	for (row = 0; row < gridSize; row++)
		for (col = 0; col < *gridColSize; col++)
		{
			//��̬��ά�����ں����еĴ���
			if (dfs(grid, gridSize, gridColSize, row, col, visit))
				nums++;
		}
	return nums;
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

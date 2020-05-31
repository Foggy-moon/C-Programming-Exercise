#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define true 1
#define false 0
#define bool int

typedef struct pisition {
	int x;
	int y;
}islandPis;

int numIslands(char** grid, int gridSize, int* gridColSize) {
	if (grid == NULL || gridSize == 0 || gridColSize == 0)
		return 0;
	//�������У��ṹ������Ԫ��������Ϊ������λ�þ�Ϊ��ʱ
	islandPis* queue = (islandPis*)malloc(sizeof(islandPis) * gridSize * gridColSize[0]);
	int row, col, front, rear, d;
	int xCur, yCur, xNew, yNew;
	int islandNum = 0;
	int dir[][2] = { {-1,0},{1,0},{0,-1},{0,1} };
	for (row = 0; row < gridSize; row++) {
		for (col = 0; col < gridColSize[0]; col++) {
			front = 0; rear = 0;
			if (grid[row][col] == '1') {
				grid[row][col] = '0';
				islandNum++;
				queue[rear].x = row;
				queue[rear].y = col;
				rear++;
				while (front < rear)
				{
					//front++���Ϊ��ǰ��λ�ó����У�frontΪ��ǰ�����λ��
					xCur = queue[front].x;
					yCur = queue[front].y;
					front++;
					//�ڵ�ǰλ��(��)�����������ĸ�����Ѱ�ҵ�
					for (d = 0; d < (sizeof(dir) / sizeof(dir[0])); d++)
					{
						xNew = xCur + dir[d][0];
						yNew = yCur + dir[d][1];
						//�ж��������Ƿ��ͼ�ڣ��Ƿ�Ϊ��
						if (xNew < 0 || xNew >= gridSize || yNew < 0 || yNew >= gridColSize[0] || grid[xNew][yNew] == '0')
							continue;
						//����λ�������
						queue[rear].x = xNew;
						queue[rear].y = yNew;
						rear++;
						grid[xNew][yNew] = '0';

					}
				}
			}
		}
	}
	return islandNum;
}

void main()
{
char grid[4][5] = { "11110","11010","11000","00000" };
int colsize = 5;
char* p[4];
for (int i = 0; i < 4; i++)
	p[i] = &grid[i];

int res = numIslands(p, 4, &colsize);
}

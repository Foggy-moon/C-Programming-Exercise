#include <stdio.h>
#include <memory.h>
void main() {
    char grid[][5] = { {"11110"},{"11010"},{"11000"},{"00000"} };
	//动态二维数组的行数、列数
    int rowNum = sizeof(grid) / sizeof(grid[0]);
    int colNum = sizeof(grid[0]) / sizeof(char);
	//动态二维数组的内存分配，内存不连续
    char** p = (char**)malloc(sizeof(char*) * rowNum);
    int i,j;
    for (i = 0; i < rowNum; i++)
    {
        p[i] = (char*)malloc(sizeof(char) * colNum);
        memset(p[i], 0, sizeof(char) * colNum);
    }

    for (i = 0; i < rowNum; i++)
        for (j = 0; j < colNum; j++)
            printf("%d ", p[i][j]);
    printf("\n");

}
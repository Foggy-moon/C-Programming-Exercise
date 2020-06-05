#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct node {
    int root;
    int rank;
}djset;

void initializeDjset(djset* islandSet, char** grid, int gridSize, int* gridColSize) {
    int row, col,i;
    for(row=0;row<gridSize;row++)
        for (col = 0; col < gridColSize[0]; col++) {
            i = row * gridColSize[0] + col;
            islandSet[i].root = -1;
            islandSet[i].rank = 0;
        }
}

int findRoot(djset* islandSet, int x) {
    while (islandSet[x].root != -1)
        x = islandSet[x].root;
    return x;
}

void unionDjset(djset* islandSet, int x, int y, int* num) {
    int x_root = findRoot(islandSet, x);
    int x_rank = islandSet[x].rank;
    int y_root = findRoot(islandSet, y);
    int y_rank = islandSet[y].rank;
    if (x_root != y_root) {
        (*num)--;
        if (x_rank > y_rank)
            islandSet[y_root].root = x_root;
        else if (x_rank < y_rank)
            islandSet[x_root].root = y_root;
        else {
            islandSet[x_root].root = y_root;
            islandSet[y_root].rank++;
        }
    }

}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (grid == NULL || gridSize <= 0 || gridColSize == NULL || gridColSize[0] <= 0)
        return 0;
    int row, col, k, totalSize = gridSize * gridColSize[0], islandNum = totalSize;
    djset* islandSet = (djset*)malloc(sizeof(djset) * totalSize);
    initializeDjset(islandSet, grid, gridSize, gridColSize);
    for(row = 0; row < gridSize; row++)
        for (col = 0; col < gridColSize[0]; col++) {
            k = row * gridColSize[0] + col;
            if (grid[row][col] == '1') {
                if (row + 1 < gridSize && grid[row + 1][col] == '1')
                {
                    int k1 = k + gridColSize[0];
                    unionDjset(islandSet, k, k1, &islandNum);
                }
                if (col + 1 < gridColSize[0] && grid[row][col + 1] == '1')
                {
                    int k1 = k + 1;
                    unionDjset(islandSet, k, k1, &islandNum);
                }
            }
            else
                islandNum--;
        }
       

    return islandNum;
}

void main() {
    char grid[][5] = { {"11000"},{"11000"},{"00100"},{"00011"} };
    char* p[4];
    for (int i = 0; i < sizeof(grid) / sizeof(grid[0]); i++)
        p[i] = grid[i];
    int col = 5;
    int res = numIslands(&p, 4, &col);
}

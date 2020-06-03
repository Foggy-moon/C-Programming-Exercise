#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define VERTICES 6
/*并查集判断是否存在环*/
void initialize(int parent[]) {
	memset(parent, -1, sizeof(int) * VERTICES);
}

int find_root(int x, int parent[]) {
	int x_root = x;
	while(parent[x_root] != -1)
		x_root = parent[x_root];
	return x_root;
}

int union_vertices(int x, int y, int parent[]) {
	int x_root = find_root(x, parent);
	int y_root = find_root(y, parent);
	if (x_root == y_root)
		return 0;
	else {
		parent[x_root] = y_root;
		return 1;
	}
}
void main()
{
	int parent[VERTICES] = { 0 };
	initialize(parent);
	int egdes[][2] = {
		{0,1},{1,2},{1,3},
		{2,4},{3,4},{2,5}
	};
	int i;
	for (i = 0; i < VERTICES; i++) {
		int x = egdes[i][0];
		int y = egdes[i][1];
		if (union_vertices(x, y, parent) == 0) {
			printf("Circle detected\n");
			exit(0);
		}
	}
	printf("No circles found\n");
}

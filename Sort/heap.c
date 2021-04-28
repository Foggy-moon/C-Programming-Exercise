#include <stdio.h>
//堆排序
//大顶堆:完全二叉树+父节点>子节点
//完全二叉树：从上到下，从左到右的顺序添加节点
//数组表示二叉树
//parent = (i-1)/2
//c1 = 2i +1
//c2 = 2i+2
void swap(int arr[], int a, int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	int arr[b] = tmp;
}
void heapify(int tree[], int n, int i)
{
	if (i >= n) {
		return;
	}
	int c1 = 2*i + 1;
	int c2 = 2*i + 2;
	int max = i;
	if(c1 < n && tree[c1] > tree[max]) {
		max = c1;
	}
	if (c2 < n && tree[c2] > tree[max]) {
		max = c2;
	}
	if (max != i) {
		swap(tree, max, i);
		heapfiy(tree, n, max);
	}
	
}

// 从最后一个节点的父节点开始构建堆，到第一个元素构建完成可以保证是一个大顶堆
void build_heap(int tree[], int n)
{
	int last_node = n - 1;
	int parent = (last_node - 1)/2;
	int i;
	for(i = parent; i >= 0; i--){
		heapify(tree, n, i);
	}
}

void heap_sort(int tree[], int n)
{
	build_heap(tree, n);
	int i;
	//将堆顶元素和最后一个元素对调，然后摘除最后一个元素(最大值到了最右边)
	for (i = n-1; i>=0; i--){
		swap(tree, i, 0);
		heapify(tree, i, 0);
	}
}
int main()
{
	int tree[] = {4, 10, 3, 5, 1, 2};
	int n = 6;
	heap_sort(tree, 6);
	heapify(tree, n, 0);
	return 0;
}
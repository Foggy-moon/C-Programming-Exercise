#include <stdio.h>
//������
//�󶥶�:��ȫ������+���ڵ�>�ӽڵ�
//��ȫ�����������ϵ��£������ҵ�˳����ӽڵ�
//�����ʾ������
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

// �����һ���ڵ�ĸ��ڵ㿪ʼ�����ѣ�����һ��Ԫ�ع�����ɿ��Ա�֤��һ���󶥶�
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
	//���Ѷ�Ԫ�غ����һ��Ԫ�ضԵ���Ȼ��ժ�����һ��Ԫ��(���ֵ�������ұ�)
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
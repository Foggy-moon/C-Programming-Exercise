#include <stdio.h>
//选择排序
//每次将剩下的数字中最大的数字和当前未排序的最右边的数字替换
int FindMax(int arr[], int n)
{
	int max = arr[0];
	int pos = 0;
	int i;
	for(i=1; i<n; i++){
		if(arr[i] > max){
			max = arr[i];
			pos = i;
		}
	}
	return pos;
}

void SelectSort(int arr[], int n)
{
	while(n > 1){
		int pos = FindMax(arr, n);
		int tmp = arr[pos];
		arr[n] = tmp;
		arr[pos] = arr[n];
		n--;
	}
}
int main()
{
	int arr[] = {1,8,8,5,3,9,6};
	SelectSort(arr, 7);
	return 0;
}
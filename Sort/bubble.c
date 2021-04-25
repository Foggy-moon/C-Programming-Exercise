#include <stdio.h>
//冒泡排序
//每次把剩下未排序的数字中最大的一位一位的移到未排序范围的最右边，就像冒泡一样
void Bubble(int arr[], int n)
{
	int i;
	int tmp;
	for(i=0; i<n-1; i++){
		if(arr[i]>arr[i+1]){
			tmp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = tmp;
		}
	}
}

void BubbleSort(int arr[], int n)
{
	int i;
	for(i=n; i>=1; i--){
		Bubble(arr, i);
	}
}
int main()
{
	int arr[] = {1,8,8,5,3,9,6};
	BubbleSort(arr, 7);
	return 0;
}
#include <stdio.h>
//插入排序
//从第二个元素开始，将该元素插入到它正确的顺序，使该位置右侧的元素都比他大
void Insert(int arr[], int n)
{
	int key = arr[n]
	while(arr[n-1] > key){
		arr[n] = arr[n-1];
		n--;
		if(n == 0){
			break;
		}
	}
	arr[n] = key; //将该元素放在合适位置，右侧元素均比它大
}

void InsertSort(int arr[], int n)
{
	int i;
	for(i=1; i<n; i++){
		Insert(arr, i);
	}
}
int main()
{
	int arr[] = {1,8,8,5,3,9,6};
	InsertSort(arr, 7);
	return 0;
}
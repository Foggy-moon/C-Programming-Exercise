#include <stdio.h>
#include <stdlib.h>
void res_int(int* arr, int start, int end, int* res)
{
	int len = end - start;
	int i;
	for (i = 0; i <= len; i++)
		res[i] = arr[start + i];
}

int gap(int a, int b)
{
	return a > b ? a - b : b - a;
}

int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
	*returnSize = k;
	int* res = (int*)malloc(sizeof(int) *(k+1));
	if (arr[arrSize - 1] <= x)
		res_int(arr, arrSize - k, arrSize - 1, res);
	else if (arr[0] >= x)
		res_int(arr, 0, k - 1, res);
	else
	{
		int left = 0, right = arrSize - 1;
		int pivot, min = gap(arr[left], x), index = left;
		while (left <= right)
		{
			pivot = (left + right) / 2;
			if (gap(arr[pivot], x) > min)
				right = pivot - 1;
			else
			{
				if (gap(arr[pivot], x) > gap(arr[pivot - 1], x))
					right = pivot - 1;
				else
					left = pivot + 1;
				index = pivot;
				min = gap(arr[pivot], x);
			}
		}
		left = index;
		right = index;
		while (right - left < k - 1)
		{
			if (gap(arr[left - 1], x) <= gap(arr[right + 1], x))
				left--;
			else
				right++;
		}
		res_int(arr, left, right, res);
	}
	return res;
}
void main()
{

    int nums[] = { 0,1,1,1,2,3,6,7,8,9 };
    int size = 9;
    int* res = findClosestElements(nums, 10, 9,4, &size);
}
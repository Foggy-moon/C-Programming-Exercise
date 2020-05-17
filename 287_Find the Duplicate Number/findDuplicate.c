#include <stdio.h>
#include <stdlib.h>

int count_smaller(int* nums, int pivot, int numsSize)
{
	int i, count = 0;
	for (i = 0; i <= numsSize - 1; i++)
	{
		if (nums[i] <= pivot)
			count++;
	}
	return count;
}

int findDuplicate(int* nums, int numsSize) {
	int left = 0, right = numsSize - 1;
	int pivot, count;
	while (left <= right)
	{
		pivot = (left + right) / 2;
		if (right == left)
			break;
		count = count_smaller(nums, pivot, numsSize);
		if (count > pivot)
			right = pivot;
		else
			left = pivot + 1;
		
	}
	return pivot;
}
void main()
{
	int nums[] = { 1,3,4,2,2 };
	int res = findDuplicate(nums, 5);

}


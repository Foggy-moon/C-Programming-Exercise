#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int getMiddle(int *nums, int left, int right)
{
	int half = (left + right) / 2;
	swap(&nums[left], &nums[half]);
	int pivot = nums[left];
	while (left < right)
	{
		while (nums[right] >= pivot && right > left)
			right--;
		nums[left] = nums[right];
		while (nums[left] <= pivot && right > left)
			left++;
		nums[right] = nums[left];
	}
	nums[left] = pivot;
	return left;


}
void quickSort(int* nums, int left,int right)
{
	if (left < right)
	{
		int pivot = getMiddle(nums, left, right);
		quickSort(nums, left, pivot - 1);
		quickSort(nums, pivot + 1, right);
	}
}
int containsDuplicate(int* nums, int numsSize) {
	int i;
	quickSort(nums,0,numsSize-1);
	for (i = 1; i <= numsSize - 1; i++)
	{
		if (nums[i] == nums[i - 1])
			return true;
	}
	return false;
}

void main()
{
	int nums[] = { 1,2,3,4 };
	int res = containsDuplicate(nums, 4);

}


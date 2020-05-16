#include <stdio.h>
#include <stdlib.h>

int getMiddle(int* nums, int left, int right)
{
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
void quickSort(int* nums, int left, int right)
{
	if (left < right)
	{
		int mid = getMiddle(nums, left, right);
		quickSort(nums, left, mid - 1);
		quickSort(nums, mid+1, right);
	}
}
int findSector(int *numslitter, int *numslarge, int littleSize, int largeSize,int *res)
{
	int  i, j=0, k = 0;
	//双指针法查找共同元素
	for(i=0;i<= littleSize-1 && j<=largeSize-1;i++)
	{
		if (i != 0)
		{
			if (numslitter[i] == numslitter[i - 1])
				continue;
		}
		while (numslitter[i] != numslarge[j])
		{
			if (j == largeSize - 1)
			{
				j++;
				break;
			}
			j++;
		}
		if (j <= largeSize - 1)
		{
			res[k++] = numslarge[j++];
		}
		else
			j=0;

	}
	return k;
	
}
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	quickSort(nums1, 0, nums1Size-1);
	quickSort(nums2, 0, nums2Size - 1);
	*returnSize = nums1Size > nums2Size ? nums2Size : nums1Size;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	if (nums1Size > nums2Size)
		*returnSize = findSector(nums2, nums1, nums2Size, nums1Size,res);
	else
		*returnSize = findSector(nums1, nums2, nums1Size, nums2Size,res);
	return res;
}

void main()
{
	int nums1[] = { 4,9,5 };
	int nums2[] = { 9,4,9,8,4};
	int returnSize = 1;
	int* res = intersection(nums1, 3, nums2, 5, &returnSize);

}


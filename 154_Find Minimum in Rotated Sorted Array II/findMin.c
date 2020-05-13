#include <stdio.h>
int judge_which_edge(int* nums, int numsSize, int pivot,int target)
{	//0左边界；1有边界
	int i;
	if (pivot > numsSize / 2)
	{
		//往右有任一非target值则pivot非出现在右边界
		for (i = pivot; i <= numsSize - 1; i++)
		{
			if (nums[i] != target)
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		//往左有任一非target值则pivot非出现在左边界
		for (i = pivot; i >=0; i--)
		{
			if (nums[i] != target)
			{
				return 1;
			}
		}
		return 0;
	}

}
int findMin(int* nums, int numsSize) {
	/*将nums拆分为两段，每段均为递增。假设最小元素为nums[index]，则第一段为nums[0]~nums[index-1]
	第二段为nums[index]~nums[numsS-1]。nums[0]>=nums[numsS-1]。进行二分查找时只要nums[pivot]>nums[0]，
	则pivot出现在第一段中,left=pivot+1，只要nums[pivot]<nums[0]，pivot肯定在第二段中，此时right=pivot-1;
	nums[pivot]=nums[0],有两种可能，第一段开始的连续元素值为nums[0],或第二段结尾连续元素值为nums[0]，
	*/
	int left = 0, right = numsSize - 1;
	int pivot, flag,  nums_left = nums[0], min = nums_left;
	while (left <= right)
	{
		pivot = (right + left) / 2;
		if (nums[pivot] > nums_left)
			left = pivot + 1;
		else if (nums[pivot] < nums_left)
		{
			right = pivot - 1;
			min = nums[pivot] > min ? min : nums[pivot];
		}
		else
		{
			//用二分法区分pivot出现在左边界还是右边界
			flag = judge_which_edge(nums, numsSize, pivot, nums_left);
			if (flag == 0)
				left = pivot + 1;
			else
				right = pivot - 1;
		}
	}
	return min;
}
void main()
{
	int nums[] = { 2,2,2,0,1 };
	int res = findMin(nums, 5);

}
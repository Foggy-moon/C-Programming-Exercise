#include <stdio.h>
int judge_which_edge(int* nums, int numsSize, int pivot,int target)
{	//0��߽磻1�б߽�
	int i;
	if (pivot > numsSize / 2)
	{
		//��������һ��targetֵ��pivot�ǳ������ұ߽�
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
		//��������һ��targetֵ��pivot�ǳ�������߽�
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
	/*��nums���Ϊ���Σ�ÿ�ξ�Ϊ������������СԪ��Ϊnums[index]�����һ��Ϊnums[0]~nums[index-1]
	�ڶ���Ϊnums[index]~nums[numsS-1]��nums[0]>=nums[numsS-1]�����ж��ֲ���ʱֻҪnums[pivot]>nums[0]��
	��pivot�����ڵ�һ����,left=pivot+1��ֻҪnums[pivot]<nums[0]��pivot�϶��ڵڶ����У���ʱright=pivot-1;
	nums[pivot]=nums[0],�����ֿ��ܣ���һ�ο�ʼ������Ԫ��ֵΪnums[0],��ڶ��ν�β����Ԫ��ֵΪnums[0]��
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
			//�ö��ַ�����pivot��������߽绹���ұ߽�
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
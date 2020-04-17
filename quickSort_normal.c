#include <stdio.h>
int getMiddle(int* nums, int left, int right)
{
    int pivot = nums[left];
    while (left < right) {
        while (nums[right] >= pivot && left < right)
            right--;
        nums[left] = nums[right];
        while (nums[left] <= pivot && left < right)
            left++;
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
}
void quickSort(int* nums, int left, int right) 
{
    while (left < right) {
        int mid = getMiddle(nums, left, right);
        quickSort(nums, left, mid - 1);
        quickSort(nums, mid + 1, right);
    }
}

void main()
{
    int nums[7] = { 1,5,3,2,7,0,10 };
    quickSort(nums, 0, 6);

}
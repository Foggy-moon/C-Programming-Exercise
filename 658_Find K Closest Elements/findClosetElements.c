#include <stdio.h>

bool isPerfectSquare(int num) {
    if (num == 1)
        return true;
    int left = 1, right = num / 2 + 1;
    int pivot;
    while (left <= right)
    {
        pivot = (left + right) / 2;
        if (pivot == num / pivot)
            return true;
        else if (pivot < num / pivot)
            left = pivot + 1;
        else
            right = pivot - 1;
    }
    return false;
}
void main()
{
    bool res = isPerfectSquare(16);

    
}
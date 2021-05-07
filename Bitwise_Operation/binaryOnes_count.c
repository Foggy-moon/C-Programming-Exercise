#include <stdio.h>
// 与运算, A & 1 == A; A & 0 ==0
int CountOnes(int num)
{
	int count = 0;
	while(num > 0){
		if ((num & 1) == 1) {
			count ++;
		}
		num = num >> 1;
	}
	return count;
}

int main()
{
	int num = 17;
	int c = CountOnes(num);
	printf("The num %d have %d ones", num, c);
}


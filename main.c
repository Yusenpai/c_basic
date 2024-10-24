#include <stdio.h>
#define NUMBER_A 10
int main(void)
{
	// Khởi tạo biến a
	char a = 1000; //1000 = 256 + 256 + 256 + 232
	// 232 - 256 = -24

	// 1000 = 0b11_11101000 = 0b11101000 = 232
	printf("%d\n",a);

	return 0;
}
#include <stdio.h>

int main(void)
{
	// Khởi tạo biến a và b
	volatile const int a = 10;
	printf("%d\n", a);

	int *ptr = &a;
	*ptr = 8;
	printf("%d\n", a);

	return 0;
}
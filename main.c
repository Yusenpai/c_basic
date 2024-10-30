#include <stdio.h>
int main()
{
	int arr[3] = {10, 20, 30};
	int *ptr = arr; // ptr trỏ tới phần tử đầu tiên của mảng
	printf("%d\n", *ptr);
}
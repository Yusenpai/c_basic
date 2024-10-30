#include <stdio.h>
int main()
{
	char arr[3] = {10, 20, 30};

	char *p = arr; // Array decay
	char(*ptrArr)[3] = &arr;
	printf("%p\n", ptrArr);
	printf("%p\n", ptrArr + 1);

	printf("%d\n", *(*ptrArr + 1));
}
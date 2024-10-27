#include <stdio.h>

int main()
{
	unsigned short a = 0b1111000011110000;
	if (a & (1 << 8))
		printf("OK\n");
	else
		printf("NO\n");
}
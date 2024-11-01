#include <stdio.h>
#include <stdlib.h>

struct Point
{
	uint8_t x;
	uint32_t y;
};

int main()
{
	printf("Kích thước của struct Point là %d\n", sizeof(struct Point));
}
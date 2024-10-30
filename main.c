#include <stdio.h>
int main()
{
	int a = 22;
	int *p = &a;
	printf("p = %u\n", p);
	p++;
	printf("p++ = %u\n", p);
	p--;
	printf("p-- = %u\n", p);

	char c = 'a';
	char *r = &c;
	printf("r = %u\n", r);
	r++;
	printf("r++ = %u\n", r);
	r--;
	printf("r-- = %u\n", r);
	return 0;
}
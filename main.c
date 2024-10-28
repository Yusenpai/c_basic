#include <stdio.h>

void funcA(int a){
	a = a + 1;
}

void funcB(int *a){
	*a = *a + 1;
}

int main(){
	int a = 10;

	funcA(a);
	printf("%d\n", a);

	funcB(&a);
	printf("%d\n", a);
	
	return 0;
}
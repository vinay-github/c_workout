#include <stdio.h>

void fun(int *, int *y);
int main() {
	int x=10, y=100;
	fun(&x, &y);
	printf("x = %d\n y = %d\n",x,y);
	return(0);
}

void fun(int *xx, int *yy) {
	xx = yy;
	printf("%d\n",*xx);
	*yy = 200;
}

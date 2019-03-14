#include <stdio.h>

void fun(int);
int main() {
	int a = 5;
	fun(a);
	return(0);
}

void fun(int a) {
	int p[3*a];
	int i;
	for(i=0; i<15; i++)
		p[i] = i*3;
	for(i=0; i<15; i++)
		printf("%d\n", p[i]);
}

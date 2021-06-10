#include <stdio.h>

int main(int argc, char *argv[]) {
	int a = 15, b = 10;

	printf("A=%d B=%d\n", a, b);
	b = (a+b);
	a = b-a;
	b = b-a;

	printf("A=%d B=%d\n", a, b);
	return(0);
}

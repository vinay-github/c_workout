#include <stdio.h>

int main() {
	int a[2], i;

	a[0] = 44;
	a[1] = 55;

	for(i = 0; i <= 1; i++) {
		printf("%d\n", a[i]);
		printf("----------------\n");
	}

	return 0;
}

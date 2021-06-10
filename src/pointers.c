#include <stdio.h>

int main() {
	int a = 33;
	int *ptr = &a;

	printf("*ptr %d\n",*ptr);
	printf("&ptr %u\n",ptr);
	printf("&a %u\n",a);
	printf("a %d\n",a);
	printf("*(&a) %d\n",*(&a));
	return(0);
}

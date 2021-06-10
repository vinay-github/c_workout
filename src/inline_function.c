#include <stdio.h>

static inline int fun2() {
	printf("second\n");
	return 0;
}

static inline int fun1_f(int x) {
	printf("First inline\n");
	fun2();
	return (x+3);
}

int main() {
	int a = 6;

	printf("*** main function\n");
	(void) fun1_F(a);
	printf("Value of a = %d\n", a);
	printf("End\n");
	return 0;
}

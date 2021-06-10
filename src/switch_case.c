#include <stdio.h>

int main() {
	int index, a = 4;

	for (index=0; index<5; index++) {
		a+=index; 
		printf("a is -- %d\n", a);
		switch (a) {
			case 4: case 5:
				printf("Value of a = %d\n", a);
				break;
			case 6: case 7:
				printf("Maybe a is 6 or 7. a=%d\n", a);
				break;
			case 8:
				printf("A is 8\n");
				break;
			default:
				printf("default\n");
		}
	}

	printf("Final a is %d\n", a);
	
	return 0;
} 

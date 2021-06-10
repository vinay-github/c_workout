/* How go-to works? */

#include <stdio.h>

int main() {
	int a = 4;
	printf("Starting main function\n");

restart:
	printf("%d Restarting\n", a);
	if ( a++ < 5 )
		goto restart;
	printf("Ending %d", a);
	return(0);
}

#include <stdio.h>

int main() {

	int c;

	c = getchar();
	printf("%c\n", c);
	
	if ( c == 's' ) 
		printf("ssssss\n");
	else if ( c == 'D' )
		printf("DDDDDD\n");
	
	
	return 0;
}

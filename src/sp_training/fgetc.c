#include <stdio.h>

int main() {
	int b;

	b = fgetc(stdin);
	printf("%d\n", b);

	if ( b == 'a' ) 
		printf("aaaaaaaaaaaaaaa\n");
	else
		printf("ssssssssssssssss\n");
	
	
	return 0;
}


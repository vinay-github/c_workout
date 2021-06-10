#include <stdio.h>
#include <string.h>

int main(void) {
	printf("%-3.4s\n", "1234567890123456789012345");

	printf("%s%.*s\n", "vinay", 3, "1234");

	char a[12];
	strcpy(a, "Indi a");
	
	printf("A=%s\n", a);	
	return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
	char str[20];
	printf("----------------\n");

	scanf("%s", str);

	//int strncmp(const char *s1, const char *s2, size_t n);
	if ((strncmp(str, "libsome", strlen("libsome"))) == 0 )
		printf("Matched\n");
	else
		printf("Nope %s\n", str);
	
	return 0;
}
	

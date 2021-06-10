#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *str;
	str = (char *)malloc(sizeof(char)*100);
	memset(str, '\0', sizeof(str));

	printf("Enter the string\n");
	fgets(str, sizeof(char)*100, stdin);

	printf("%s\n", str);
	puts(str);

	free(str);
	return 0;
}

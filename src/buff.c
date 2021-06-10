#include <stdio.h>
#include <string.h>

int main() {
	char *str = "India";
	char ab[20];
	int len;
	len = strlen(str);

	memset(ab, '\0', sizeof(ab));
	strncpy(ab, str, strlen(str));
	
	printf("Len = %d String = %s\n", len, str);
	printf("Len = %ld String = %s\n", strlen(ab), ab);
	return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
	int len;
	char str[100];

	printf("Enter the string:");
	scanf("%s", str);

	len = strlen(str);

	for (int i=0; i<((len+1)/2); i++) {
		if (str[i] != str[len-1-i]) {
			printf("Not a pali\n");
			return 0;
		}
	}
	printf("Pali\n");
	return 0;
}

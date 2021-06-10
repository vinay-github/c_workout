#include <stdio.h>

int main() {

	int a;
	char msg[20];

	while (1) {
		scanf("%d%[^\n]", &a, msg);
		printf("a=%d\nmsg=%s\n", a, msg);
	}
	return 0;
}
	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *tmp;
	tmp = malloc(10);

	strcpy(tmp, "India");
	printf("%s\n", tmp);
	free(tmp);
	tmp=NULL;
	
	if (tmp == NULL) {
		printf("When checked with NULL\n");
	}
	if (tmp != 0) {
		printf("When checked != 0\n");
	}
	if (tmp != NULL) {
		printf("When checked != NULL\n");
	}
	if (tmp == 0) {
		printf("When checked == 0\n");
	}

	if (tmp) {
		printf("Freeing tmp again\n");
		free(tmp);
	}

	tmp = "Okayaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	printf("This shouldn't happen %s\n", tmp);
	
	return 0;
}

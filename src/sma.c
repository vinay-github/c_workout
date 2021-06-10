#include <stdio.h>
int main() {
	void *a;
	a = "thuis";
	printf("%c\n", ((char *)a)[0]);
	return(0);
}

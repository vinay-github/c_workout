#include <stdio.h>
#include <string.h>

int main() {
	char buf[] = "ThisisIndia";

	printf("Buf = %s\n", buf);
	printf("1.stlen = %ld\n", strlen(buf));
	printf("stlen = %ld\n", strlen(&buf[4]));


	return 0;
}

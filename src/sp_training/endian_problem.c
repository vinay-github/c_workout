/* Program to identify endian of the machine */

#include <stdio.h>
#include <arpa/inet.h>

int main (void) {
	unsigned int num = 413, conv;
	char *c = (char *) &num;
	
	if (*c == 0x12) {
		printf("Big endian machine (0x%X -> %X).\n", num, *c);
		conv = ntohl(num);
		c = (char *) &conv;
		printf("Convert to host byte order (0x%X -> %X)\n",num, *c);
	}
	else {
		printf("Little endian machine (0x%X -> %X)\n", num, *c);
		conv = htonl(num);
		c = (char *) &conv;
		printf("Converted to network byte order (0x%X -> %X)\n", num, *c);
	}

	num = htons(413);
	printf("Number is %d\n", num);
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t unilen(
const unsigned short *s)
{
	const unsigned short *s0 = s;
	while (*s != 0)
		s++;
	return (s - s0);
}


void copy_c_by_c(unsigned short *buf, int len) {
	char c = 'a';
	int i = 0;

	if (i == 0) {
		buf[i] = '.';
		i++;
	}
	
	for(;;) {
		if ((i+1) == len) {
			buf[i] = '.';
			i++;
			break;
		}
		buf[i] = c;
		i++;
	}
	printf("i value %d\n", i);
}

void print_cbyc(unsigned short *buf, unsigned long len) {
	int i = 0;
	char str[100];
	long int le;

	memset(str, '\0', 100);



printf("---------------------\n");	
	while(i++ !=len) {
		if ( i == 0 ) continue;
		printf("%c", buf[i]);
	}
	printf("\n");
	

	i = 0;
	while(buf[i] != '\0') {
		printf("%c\n---\n", buf[i]);
		str[i] = buf[i];
		i++;
	}
	le = strlen(str);

	printf("Len = %ld Str = %s\n", strlen(str), str);

	le = le-2;
	str[le+1] = '\0';
	printf("2 Len = %ld Str = %s\n", le, str);
	
}

int main() {
	int i;
	int length = 13;
	unsigned long len;

	unsigned short *buf;
	buf = malloc(length);

	copy_c_by_c(buf, 10);
	len = unilen(buf);
	print_cbyc(buf, len);

	printf("malloc Length = %d\n", length);
	printf("unilen = %ld\n", len);
	return 0;
}
	

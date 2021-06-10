#include <stdio.h>

void reverse(char *begin, char *end) {
	char temp;

	while(begin<end) {
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}
// This is India

void reverse_str(char *str) {
	char *temp = str;
	char *begin = str;

	while(*temp) {
		temp++;
		if(*temp == '\0')
			reverse(begin, temp-1);
		else if(*temp == ' ') {
			reverse(begin, temp -1);
			begin = temp+1;
		}
	}

	reverse(str, temp-1);
}


int main() {
	char str[] = "This is India";

	reverse_str(str);
	printf("%s\n", str);

	return 0;
}	

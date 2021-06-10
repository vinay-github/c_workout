#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sample_s {
	short a;
	int num;
	unsigned short *name;
};
struct sample_s *sample_ss = NULL;
short k = 10;
unsigned short *mm = &k;


int fun(int num) {
	char str[10];
	printf("Starting ........... %d\n", sample_ss->a);

	if (sample_ss->a) {	
		printf("here\n");
		sample_ss->num = num;
		sample_ss->name = mm;
	}
	else {
		sample_ss->a = 1;
		sample_ss->num = num;
		sample_ss->name = mm;
	}
	
	printf("Reached ...........\n");
	printf("Number = %d\nName = %d\n", sample_ss->num, *sample_ss->name);
	return 0;
}

int main() {
	sample_ss = (struct sample_s *) malloc (sizeof(struct sample_s));
	fun(15);
//	printf("main second - Number = %d\nName = %d\n", sample_ss->num, sample_ss->name);
	
	fun(20);
//	printf("main end - Number = %d\nName = %d\n", sample_ss->num, sample_ss->name);
	
	return 0;
}
	
	

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sample_s {
	int num;
	char name[20];
} *sample_ss;
int a;

int fun(int num) {
	sample_ss = (struct sample_s *) malloc(sizeof(struct sample_s));

	printf("Starting ...........\n");

	if (a == 1) {	
		sample_ss->num = num;
		strcpy(sample_ss->name, "Jordan");
	}
	
	printf("Reached ...........\n");

	printf("Number = %d\nName = %s\n", sample_ss->num, sample_ss->name);
	return 0;
}

int main() {
	a = 1;
	fun(15);
	printf("main second - Number = %d\nName = %s\n", sample_ss->num, sample_ss->name);
	
	a = 0;
	fun(20);

	printf("main end - Number = %d\nName = %s\n", sample_ss->num, sample_ss->name);
	return 0;
}
	
	

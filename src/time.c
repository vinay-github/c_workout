#include <time.h>
#include <stdio.h>

int main() {
	time_t index;
	index = time(NULL) % 2;
	
	printf("index = %ld\ntime(NULL) = %ld\n", index, time(NULL));
	return 0;
}

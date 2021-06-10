#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

int main(void) {
	char *str;
  size_t pagesize = getpagesize();

  printf("System page size: %zu bytes\n", pagesize);

  str = mmap(NULL, 4096, MAP_ANONYMOUS, 0, 0);
  
	if (str == MAP_FAILED) {
    	printf("Could not mmap");
    	return 1;
  	}

  strcpy(str, "Hello, poftut.com");
	
  printf("Contents of region: %s\n", str);

  }
  // getpagesize
  return 0;
}

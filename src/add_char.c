#include <stdio.h>
#include <string.h>

int main(void) {
	char a[] = "/media/nss/DFSVOL9/$DFS_5EB41843.000";
	printf("a = %s %ld\n", a, sizeof(a));
	
	char *pos = strchr(a, '$');
	if(pos) {
		printf("Pos = %s\n", pos);
		memmove(pos+1, pos, strlen(pos));
		pos[0] = '\\';
		printf("Pos = %s\n", pos);
	}
	printf("a = %s %ld\n", a, sizeof(a));
	
	return 0;
}
	

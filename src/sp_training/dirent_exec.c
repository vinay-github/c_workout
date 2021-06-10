/* Program to understand the usage of opendir, readdir and dirent structure */

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	DIR	*dp;
	struct dirent *dir_st;

	if (argc != 2) {
		printf("Usage: %s directory\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	dp = opendir(argv[1]);
	if (!dp) {
		printf("Failed to open directory (%m)\n");
		exit(EXIT_FAILURE);
	}

	if ((dir_st = readdir(dp)) == NULL) {
		printf("readdir() failed (%m)\n");
		closedir(dp);
		exit(EXIT_FAILURE);
	}
	
	printf("First entry...\n"); 
	printf("Inode = %ld\nOffset = %ld\nRecord Length = %d\nType = %d\nName = %s\n", 
			dir_st->d_ino, 
			dir_st->d_off, 
			dir_st->d_reclen, 
			dir_st->d_type, 
			dir_st->d_name);
	printf("------------------------------------------------------\n");

	while ((dir_st = readdir(dp)) != NULL) {
		printf("%s\t", dir_st->d_name);
	}

	printf("\n");
	closedir(dp);	
	return 0;
}

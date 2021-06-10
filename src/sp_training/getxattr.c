#include <stdio.h>
#include <sys/types.h>
#include <attr/xattr.h>
#include <errno.h>
#include <string.h>

int main()
{
	const char *path, *name;
	ssize_t rec;
	char	value[1024];

	path = "/home/vinay/scratch/c_notes/src/sp_training/cat_util.c";
	name = "change";

	printf("%s %s\n", path, name);

	rec = getxattr(path, name, value, sizeof(value));

	printf("%ld %s \n", rec, strerror(errno));
	printf("name = %s\n");
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/xattr.h>
/* dumpmem: dumps an n byte area of memory to screen */
void dumpmem (const void *mem, unsigned int n)
{
	enum { NLONGS = 4,
		NCHARS = NLONGS * sizeof(long) };
	const unsigned long	*p = mem;
	const char		*c = mem;
	unsigned		i, j;
	unsigned		q, r;
	q = n / NCHARS;
	r = n % NCHARS;
	for (i = 0; i < q; i++) {
		printf("%8p:", p);
		for (j = 0; j < NLONGS; j++) {
			printf(" %8lx", *p++);
		}
		printf(" | ");
		for (j = 0; j < NCHARS; j++, c++) {
			printf("%c", isprint(*c) ? *c : '.');
		}
		printf("\n");
	}
	if (!r) return;
	printf("%8p:", p);
	for (j = 0; j < r / sizeof(long); j++) {
		printf(" %8lx", *p++);
	}
	for (; j < NLONGS; j++) {
		printf("         ");
	}
	printf(" | ");
	for (j = 0; j < r; j++, c++) {
		printf("%c", isprint(*c) ? *c : '.');
	}
	printf("\n");
}
void usage (void)
{
	pr_usage("-f<file> -x<attribute>");
}
int main (int argc, char *argv[])
{
	char	*file = "";
	char	*xattr = "";
	ssize_t	size;
	char	value[1024];
	file = "./cat_util.c";
	xattr = "some";
	size = getxattr(file, xattr, value, sizeof(value));
	if (size < 0) {
		printf("file=%s xattr=%s returned:", file, xattr);
	}
	printf("%s=\n", xattr);
	dumpmem(value, size);
	return 0;
}

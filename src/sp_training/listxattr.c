#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/xattr.h>

int main(int argc, char *argv[])
{
	ssize_t buflen, keylen, vallen;
    char *buf, *key, *val, *pathname;

    if (argc != 2) {
    	printf("Usage: %s pathname\n", argv[0]);
        exit(EXIT_FAILURE);
    }

	pathname = argv[1];

    buflen = listxattr(pathname, NULL, 0);
    if (buflen == -1) {
    	perror("listxattr");
        exit(EXIT_FAILURE);
    }
    
	if (buflen == 0) {
    	printf("%s has no attributes.\n", pathname);
        exit(EXIT_SUCCESS);
    }

    buf = malloc(buflen);
    if (buf == NULL) {
    	perror("malloc");
        exit(EXIT_FAILURE);
    }

    buflen = listxattr(pathname, buf, buflen);
    if (buflen == -1) {
    	perror("listxattr");
        exit(EXIT_FAILURE);
    }

	printf("buflen from listxattr = %ld\n", buflen);

    key = buf;
    while (buflen > 0) {

    	//Output attribute key.
    	printf("%s: ", key);

    	vallen = getxattr(pathname, key, NULL, 0);
    	if (vallen == -1)
    		perror("getxattr");
    
		if (vallen > 0) {
    		val = malloc(vallen + 1);
    	    if (val == NULL) {
    	    	perror("malloc");
    	        exit(EXIT_FAILURE);
    	    }

    		vallen = getxattr(pathname, key, val, vallen);
    		if (vallen == -1)
    			perror("getxattr");
    		else {
    			val[vallen] = 0;
    		    printf("%s", val);
			}
    		free(val);
    	} 
		else if (vallen == 0)
    		printf("<no value>");

    	printf("\n");

    	keylen = strlen(key) + 1;
    	buflen -= keylen;
    	key += keylen;
    }

    free(buf);
	return 0;
}

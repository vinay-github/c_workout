/* To demostrate how extern works across files. 
	Please check for extern_2.c file */

#include <stdio.h>
 
int count ;
extern void write_extern();
 
int main() {
   count = 5;
   write_extern();
	printf("In the first extern file\n");
   return(0);
}


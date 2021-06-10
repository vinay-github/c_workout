/* What happens when your #define 'd and constant is of same name */

#include <stdio.h>

#define one 100
#define TWO 200

int main() {
	#define TH	3
	const int TW = 2;
	printf("The total value of two constants is %d %d\n", one*TWO*TH, TW);
	printf("Two value is %d\n",TW);
	return(0);
}


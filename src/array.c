#include <stdio.h>

void fun(int []);
int *fun_array();

int main() {
    int a[5];
    int *p;
    fun(a);
    for(int i=0; i<5; i++)
        printf("%d\n",a[i]);
    p = fun_array();
    for(int i=0; i<5; i++)
        printf("%d\n",p[i]);
    
    return(0);
}

void fun(int a[]) {
    for(int i=0; i<5; i++)
        a[i] = i+2;
}

int *fun_array() {
	static int p[5];
	for(int i=3; i< 8; i++)
		p[i] = i*5;
	return p;
}

#include <stdio.h>
 #include <unistd.h>

int call_function()
{
		int a = 33;
		if (a==3) 
				goto ERR;
		a = 4;
ERR:
		close(a);
		return -19999;
}


int status(unsigned long *st)
{
	unsigned long a;
	a = 22;
	*st = a;
	
	return 0;
}

int main()
{
		int a, tmp;
		a = call_function();
		printf("A is %d\n", a);
a = 44;
		tmp = status((unsigned long *)&a);
		printf("Tmp is %d\n", a);
		printf("Tmp is %d\n", tmp);
		return 0;
}

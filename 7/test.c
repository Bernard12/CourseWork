#include <stdio.h>

int func3(int *a)
{
	int z[20];
	z[2]=228;
	int b=z[*a];
	printf("%d\n",b);
}

int func2(int* a)
{
	(*a)++;
	func3(a);
}

int func(int* a)
{
	(*a)++;
	func2(a);
}

int main()
{
 	int test=0;
	func(&test);
	printf("%d\n\n",test);
}

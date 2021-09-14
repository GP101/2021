#include <stdio.h>

double Fun(double x)
{
	return x * x;
}

int main(void)
{
	int a = 1;
	int b = 2;
	int* pa; // pa contains location of integer == pointer
	pa = &a; // &a addresss of variable 'a'
	         // &: address-of operator
	//printf("%i,%i\n", a, b); // 1,2
	//printf("%p,%p,%i\n", pa, &pa, *pa); // *: contents-of operator
	//printf("%i\n", (char*)&a - (char*)&b); // 4 in Release conf. x86 platform
	{
		int a = 4;
		printf("%i,%i\n", a, *pa); // 4, 1
	}
}

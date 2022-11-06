#include <stdio.h>

int k = 5; // global variable

int main()
{
	int i = 2; // local variable
	int j = 3;
	int* ip; // local address varialbe(poiter varialbe) // * : part of variable declaration
	//ip = 1; // syntax error
	ip = &i; // & : address-of operator
	printf("%i,%p,%p\n", i, &i, ip); // 2, [5000], [5000]
	printf("%i\n", &i == ip); // 1

	printf("%i,%p,%p\n", *ip, &ip, ip ); // 2, [4992], [5000] // * : contents-of operator
	2 * 3; // * : multiplication operator

	//{
	//	int i = 4; // local variable
	//	printf("%i\n", i); // 4
	//	printf("%i\n", j); // 3
	//	printf("%i\n", k); // 5
	//}
	//printf("%i\n", i); // 2

	return 0;
}
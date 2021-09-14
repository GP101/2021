#include <stdio.h>

typedef double (*FUN_TYPE)(double x); // 'FUN_TYPE' type == function pointer variable type

double Fun(double x)
{
	return x * x;
}

double NumericalDifferentiation(FUN_TYPE f, double a, double h = 0.0001)
{
	double y1 = f(a + h);
	double y0 = f(a);
	return (y1 - y0) / h;
}

int main(void)
{
	double t = 0.0;
	//double (*fp)(double x); // 'fp' variable == function pointer variable
	FUN_TYPE fp;

	(2 + 3);
	Fun; // start address of 'Fun' function, function pointer
	fp = Fun;
	fp(2); // () : function call operator

	printf("%g,%g\n", Fun(2), fp(2)); // 4, 4

	printf("Fun(3)=%g, Fun'(3)=%g\n"
		, Fun(3), NumericalDifferentiation(Fun, 3, 0.00001));
}

#include <stdio.h>

double f(double x, double y); // function declaration

int main()
{
	double t2;
	t2 = f(1, 2); // function call(use)
	printf("hello %f", t2);
	return 0;
}

// f(x,y) = x*x + 2*y
double f(double x, double y) // function definition
{
	double t;
	t = x * x + 2 * y;
	return t;
}

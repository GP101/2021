#include <stdio.h>

using FUNCTION = double(*)(double x);
using FUNCTION2 = double(*)(double base_, double x);

double SquareFunction(double x)
{
	return x * x;
}

double NewtonsDifference(FUNCTION f, double x, double dx = 0.0001)
{
	const double y0 = f(x);
	const double y1 = f(x + dx);
	return (y1 - y0) / dx;
}

int main(void)
{
	double result = NewtonsDifference(SquareFunction, 1.0);
	printf("%g\r\n", result);
}

#include <stdio.h>

double g(double x)
{
	double t; // variable declaration
	double f(double x); // 1) funcation declaration
	t = f(x) + x + 5; // 3) f(x) funcation call
	return t;
}

// 2) function definition
double f(double x)
{
	double t = 0;
	t = x * x;
	return t;
}

//double f2(double x) { return x * x; }

void main()
{
	double t;
	t = g(2);
	printf("%g\r\n", t);
}
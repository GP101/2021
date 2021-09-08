#include <math.h> // declaration for sqrt()
#include <stdio.h> // declaration for printf()

double f(double x); // 1) function declaration

// g(x) = f(x) + x + 5;
double g(double x)
{
	double t = 0.0;
	t = f(x) + x + 5; // f(x), 3) funcation call
	return t;
}

// h(x,y) = f(x) + g(x)
double h(double x, double y)
{
	return f(x) + g(x);
}

double f(double x) // 2) function definition
{
	return x * x;
}

int main()
{ 
	double t = 2.0;
	double t2;
	t2 = sqrt(-1); // call
	printf("%g\n", t2);
}

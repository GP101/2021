#include <stdio.h>

struct Complex
{
	double r;
	double i;
};

Complex Add(Complex a, Complex b)
{
	Complex t;
	t.r = a.r + b.r;
	t.i = a.i + b.i;
	return t;
}

Complex Add(double r, Complex b)
{
	Complex t;
	t.r = r + b.r;
	t.i = 0.0 + b.i;
	return t;
}

Complex Add(Complex a, double r)
{
	Complex t;
	t.r = a.r + r;
	t.i = a.i + 0.0;
	return t;
}

Complex Negate(Complex a)
{
	Complex t;
	t.r = -a.r;
	t.i = -a.i;
	return t;
}

Complex Subtract(Complex a, Complex b)
{
	Complex t;
	t.r = a.r - b.r;
	t.i = a.i - b.i;
	return t;
}

Complex Subtract(double r, Complex b)
{
	Complex t;
	t.r = r - b.r;
	t.i = 0.0 - b.i;
	return t;
}

Complex Subtract(Complex a, double r)
{
	Complex t;
	t.r = a.r - r;
	t.i = a.i - 0.0;
	return t;
}

Complex Multiply(Complex a, Complex b)
{
	Complex t;
	t.r = a.r * b.r - a.i * b.i;
	t.i = a.r * b.i + a.i * b.r;
	return t;
}

Complex Multiply(double r, Complex b)
{
	Complex t;
	t.r = r * b.r - 0.0 * b.i;
	t.i = r * b.i + 0.0 * b.r;
	return t;
}

Complex Multiply(Complex a, double r)
{
	Complex t;
	t.r = a.r * r - a.i * 0.0;
	t.i = a.r * 0.0 + a.i * r;
	return t;
}

int main(void)
{
	Complex a{ 1,2 };
	Complex c = Multiply(a, 2);
	printf("(%g,%g)\r\n", c.r, c.i);
}

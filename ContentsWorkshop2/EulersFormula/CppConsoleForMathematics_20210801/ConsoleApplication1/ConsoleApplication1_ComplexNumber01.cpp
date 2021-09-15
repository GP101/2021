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

Complex Multiply(Complex a, Complex b)
{
	Complex t;
	t.r = a.r * b.r - a.i * b.i;
	t.i = a.r * b.i + a.i * b.r;
	return t;
}

int main(void)
{
	Complex a{ 0,1 };
	Complex b{ 0,1 };
	Complex c = Multiply(a, b);
	printf("(%g,%g)\r\n", c.r, c.i);
}

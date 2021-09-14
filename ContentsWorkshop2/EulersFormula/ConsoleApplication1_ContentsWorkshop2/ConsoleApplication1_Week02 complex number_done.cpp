#include <stdio.h>

struct Complex
{
	double r;
	double i;
};

Complex operator+(Complex a, Complex b)
{
	Complex t;
	t.r = a.r + b.r;
	t.i = a.i + b.i;
	return t;
}

Complex operator+(double r, Complex b)
{
	Complex t;
	t.r = r + b.r;
	t.i = 0.0 + b.i;
	return t;
}

Complex operator+(Complex a, double r)
{
	Complex t;
	t.r = a.r + r;
	t.i = a.i + 0.0;
	return t;
}

Complex operator-(Complex a)
{
	Complex t;
	t.r = -a.r;
	t.i = -a.i;
	return t;
}

Complex operator-(Complex a, Complex b)
{
	Complex t;
	t.r = a.r - b.r;
	t.i = a.i - b.i;
	return t;
}

Complex operator-(double r, Complex b)
{
	Complex t;
	t.r = r - b.r;
	t.i = 0.0 - b.i;
	return t;
}

Complex operator-(Complex a, double r)
{
	Complex t;
	t.r = a.r - r;
	t.i = a.i - 0.0;
	return t;
}

Complex operator*(Complex a, Complex b)
{
	Complex t;
	t.r = a.r * b.r - a.i * b.i;
	t.i = a.r * b.i + a.i * b.r;
	return t;
}

Complex operator*(double r, Complex b)
{
	Complex t;
	t.r = r * b.r - 0.0 * b.i;
	t.i = r * b.i + 0.0 * b.r;
	return t;
}

Complex operator*(Complex a, double r)
{
	Complex t;
	t.r = a.r * r - a.i * 0.0;
	t.i = a.r * 0.0 + a.i * r;
	return t;
}

int main(void)
{
	Complex a{ 1,2 };
	Complex i{ 0,1 };
	Complex c = a * 2;

	printf("(%g,%g)\r\n", c.r, c.i);
	printf("(%g,%g)\r\n", (i * i).r, (i * i).i);
}

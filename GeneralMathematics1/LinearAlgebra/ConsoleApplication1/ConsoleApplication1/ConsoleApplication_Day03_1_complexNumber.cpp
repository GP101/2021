#include <stdio.h>

struct Complex
{
	double real;
	double img;
};

void Set(Complex a, double r, double im)
{
	a.real = r;
	a.img = im;
}

Complex Add(Complex a, Complex b)
{
	Complex t;
	t.real = a.real + b.real;
	t.img = a.img + b.img;
	return t;
}

Complex Multiply(Complex a, Complex b)
{
	Complex t;
	t.real = a.real * b.real - a.img * b.img;
	t.img = a.real * b.img + b.real * a.img;
	return t;
}

void Print(Complex a)
{
	printf("(%g,%g)\n", a.real, a.img);
}

int main()
{
	Complex a{ 2,2 };
	Complex b{ 0,2 };
	Complex c;
	Complex d;
	c = Add(a, b);
	d = Multiply(a, b);
	Print(c); // (2,4)
	Print(d); // (-4,4)
	//a.real = 2;
	//a.img = 1;
	Set(a, 2, 1);
	//b.real = 1;
	//b.img = 2;
	Set(b, 1, 2);
	Print(Multiply(a, b)); // (0,5)
	return 0;
}
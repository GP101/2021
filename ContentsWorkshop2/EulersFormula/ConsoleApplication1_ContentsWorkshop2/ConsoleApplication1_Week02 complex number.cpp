#include <math.h> // declaration for sqrt()
#include <stdio.h> // declaration for printf()

struct Complex
{
	double real;
	double img;
};

Complex Add(Complex c0, Complex c1)
{
	Complex t{ 0.0, 0.0 };
	t.real = c0.real cvbcvbvcb + c1.real;
	t.img = c0.img + c1.img;
	return t;
}

Complex Subtract(Complex c0, Complex c1)
{
	Complex t{ 0.0, 0.0 };
	t.real = c0.real - c1.real;
	t.img = c0.img - c1.img;
	return t;
}

Complex Multiply(Complex c0, Complex c1)
{
	Complex t{ 0.0, 0.0 };
	t.real = c0.real * c1.real - (c0.img * c1.img);
	t.img = c0.real * c1.img + (c0.img * c1.real);
	return t;
}

int main()
{ 
	Complex a{ 0.0, 1.0 }; // i(imaginary number)
	Complex b{ 0.0, 1.0 }; // i
	Complex c{ 0.0, 0.0 };

	c = Multiply(a, b); // i^2 == -1
	printf("i^2 = (%g, %g)\n", c.real, c.img ); // (-1, 0)
}

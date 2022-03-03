#include <math.h>
#include <stdio.h>

// [1]
double f(double x);
double Test(double x);
double g(double x, double y);
double Test2(double a, double b);

// rule of the language
int main()
{
    Test2(1, 3); // [2] function use(call)
    f(2);
    double d = 4;
    double t;
    t = sqrt(d); // call
    printf("%g\n", t); // call
}

// math function 3
// g(x,y) = f(x) + y*y
double g(double x, double y)
{
    double t;
    t = f(x) + y * y;
    return t;
}

// math function
// f(x) = x * x
// C function
double f(double x)
{
    double t;
    t = x * x;
    return t;
}

// math function 2
// Test(x) = x*x + 2
// C function
double Test(double x)
{
    double temp;
    temp = x * x + 2;
    return temp;
}

// math function 4
// Test2(a,b) = f(a) * f(a) + a*b
// [1] function definition
double Test2(double a, double b)
{
    double resultt;
    resultt = f(a) * f(a) + a * b;
    return resultt;
}

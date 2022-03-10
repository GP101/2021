#include <stdio.h>
#include <math.h>

struct Vector2
{
	double x;
	double y;
};

// vector vector addition
Vector2 Add(Vector2 v, Vector2 w);
// scalar vector multiplication
Vector2 Multiply(double a, Vector2 v);
double Cross(Vector2 v, Vector2 w);
double Length(Vector2 v);

int main()
{
	Vector2 v{ 1,0 };
	Vector2 w{ 1,1 };
	printf("area = %g\n"
		, Cross(Multiply(2, v), Multiply(2, w)) / 2.0);
	return 0;
}

Vector2 Add(Vector2 v, Vector2 w)
{
	//Vector2 t{ v.x + w.x, v.y + w.y };
	Vector2 t;
	t.x = v.x + w.x;
	t.y = v.y + w.y;
	return t;
}

//Vector2 Multiply(double a, Vector2 v) // by Abrorbek
//{
//	Vector2 t2;
//	t2.x = a * v.x;
//	t2.y = a * v.y;
//	return t2;
//}

Vector2 Multiply(double a, Vector2 v) // by Abrorbek
{
	return Vector2{ a * v.x, a * v.y };
}

double Cross(Vector2 v, Vector2 w)
{
	double temp;
	temp = v.x * w.y - w.x * v.y;
	return temp;
}

double Length(Vector2 v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

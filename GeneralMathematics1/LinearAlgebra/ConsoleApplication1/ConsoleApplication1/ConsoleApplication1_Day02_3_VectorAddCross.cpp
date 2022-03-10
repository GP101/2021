#include <stdio.h>

struct Vector2
{
	double x;
	double y;
};

// vector vector addition
Vector2 Add(Vector2 v, Vector2 w);
// scalar vector multiplication
Vector2 Multiply(double a, Vector2 v);

int main()
{
	Vector2 v;
	v.x = 2;
	v.y = 1;

	Vector2 w{1,3};

	Vector2 r;
	r = Add(v, w);
	printf("(%g,%g)\n", r.x, r.y); // (3,4)

	r = Multiply(2, r);
	printf("(%g,%g)\n", r.x, r.y); // (6,8)

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
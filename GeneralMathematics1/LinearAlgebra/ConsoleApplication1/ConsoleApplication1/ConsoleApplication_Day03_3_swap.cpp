#include <stdio.h>

void Swap(int* i, int* j)
{
	int t;
	t = *i;
	*i = *j;
	*j = t;
}

int main()
{
	int i = 2;
	int j = 3;
	Swap(&i, &j);
	printf("%i,%i\n", i, j);
	return 0;
}
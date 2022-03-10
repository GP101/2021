#include <stdio.h>
#include <math.h>

int main()
{
	double t;
	t = pow(2, 3);
	printf("%g\n", t); // 8
	double t2;
	t2 = sqrt(4); // t2 == 2
	printf("%g\n", t2); // 2
	//double t3;
	//double t4;
	////t3 = pow(3, 2);
	////t4 = sqrt(t3);
	//t4 = sqrt(pow(3, 2));
	//printf("%g\n", t4); // 3

	printf("%g\n", sqrt(pow(3, 2))); // 3
	printf("%g\n", sqrt(2)); // 1.141...
	printf("%g\n", pow(2, 1.0 / 2.0));// 1.141...
	printf("%g\n", pow(27, 1.0 / 3.0));// 3
	return 0;
}

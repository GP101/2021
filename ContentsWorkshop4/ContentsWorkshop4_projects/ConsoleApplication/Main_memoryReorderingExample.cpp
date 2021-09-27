#include <thread>
#include <iostream>

int a{ 0 };
int b{ 0 };
int c{ 0 };
int notification{ 0 };

void set_values()
{
    a = 1;
    b = 2;
    c = 3;
    notification = 1;
}

void calculate()
{
    while (notification != 1);
    a += b + c;
}

void reset()
{
    a = 0;
    b = 0;
    c = 0;
    notification = 0;
}

int main()
{
    a = 6; //just to allow first iteration

    for (int i = 0; a == 6; i++)
    {
        reset();
        std::thread t1(calculate);
        std::thread t2(set_values);

        t1.join();
        t2.join();
        std::cout << "Iteration: " << i << ", " "a = " << a << std::endl;
    }
    return 0;
}

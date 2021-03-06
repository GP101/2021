#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

const int g_numLoop = 10;
int g_value = 0;

void WorkerThread1(int param)
{
    for (int i = 0; i < g_numLoop; ++i) {
        g_value += 1;
    }
}

void WorkerThread2(int param)
{
    for (int i = 0; i < g_numLoop; ++i) {
        g_value -= 1;
    }
}

int main()
{
    std::thread worker1(WorkerThread1, 1);
    std::thread worker2(WorkerThread2, 11);

    worker1.join();
    worker2.join();

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << g_value << std::endl;
}

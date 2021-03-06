#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

const int g_numLoop = 100000;
int g_value = 0;
std::mutex  g_m;

void WorkerThread1(int param)
{
    for (int i = 0; i < g_numLoop; ++i) {
        g_m.lock();
        g_value += 1;
        g_m.unlock();
    }
}

void WorkerThread2(int param)
{
    for (int i = 0; i < g_numLoop; ++i) {
        g_m.lock();
        g_value -= 1;
        g_m.unlock();
    }
}

int main()
{
    std::thread worker1(WorkerThread1, 1);
    std::thread worker2(WorkerThread2, 11);

    worker1.join();
    worker2.join();
    std::cout << g_value << std::endl;
}

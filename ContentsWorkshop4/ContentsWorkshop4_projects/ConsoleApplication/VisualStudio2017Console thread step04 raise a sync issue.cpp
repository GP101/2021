#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

const int g_numLoop = 10;
int g_value = 0;
std::mutex  g_m;

void WorkerThread1(int param)
{
    for (int i = 0; i < g_numLoop; ++i) {
        std::unique_lock<std::mutex> lock(g_m);
        g_value += 1;
        std::cout << g_value 
            << ", id=" << std::this_thread::get_id() << std::endl;
    }
}

void WorkerThread2(int param)
{
    for (int i = 0; i < g_numLoop; ++i) {
        std::unique_lock<std::mutex> lock(g_m);
        g_value += 1;
        std::cout << g_value
            << ", id=" << std::this_thread::get_id() << std::endl;
    }
}

int main()
{
    std::thread worker1(WorkerThread1, 1);
    std::thread worker2(WorkerThread2, 11);

    worker1.join();
    worker2.join();
}

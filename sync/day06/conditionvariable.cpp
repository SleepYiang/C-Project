// ConditionVariable.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

int num = 1;
std::mutex mtx_num;
std::condition_variable cvA;
std::condition_variable cvB;

void PoorImplemention()
{
    std::thread t1([]()
    {
        for (;;)
        {
            {
                std::lock_guard<std::mutex> lock(mtx_num);
                if (num == 1)
                {
                    std::cout << "thread A print 1....." << std::endl;
                    num++;
                    continue;
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    });

    std::thread t2([]()
    {
        for (;;)
        {
            {
                std::lock_guard<std::mutex> lock(mtx_num);
                if (num == 2)
                {
                    std::cout << "thread B print 2....." << std::endl;
                    num--;
                    continue;
                }
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    });

    t1.join();
    t2.join();
}

void ResonableImplemention()
{
    std::thread t1([]()
    {
        for (;;)
        {
            std::unique_lock<std::mutex> lock(mtx_num);

            //写法一
            //while (num != 1) {
            //	cvA.wait(lock);
            //}

            //写法二
            cvA.wait(lock, []()
            {
                return num == 1;
            });

            num++;
            std::cout << "thread A print 1....." << std::endl;
            cvB.notify_one();
        }
    });

    std::thread t2([]()
    {
        for (;;)
        {
            std::unique_lock<std::mutex> lock(mtx_num);
            cvB.wait(lock, []()
            {
                return num == 2;
            });

            num--;
            std::cout << "thread B print 2....." << std::endl;
            cvA.notify_one();
        }
    });

    t1.join();
    t2.join();
}

int main()
{
    //PoorImplemention();
    //ResonableImplemention();
    return 1;
}

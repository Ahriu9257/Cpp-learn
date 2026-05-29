#include "ThreadPool.h"

#include <atomic>
#include <iostream>

int main()
{
    std::atomic<int> counter{0};

    {
        ThreadPool pool(4);

        // 提交 100 个任务，验证析构时会等待所有 worker 完成。
        for (int i = 0; i < 100; ++i)
        {
            pool.submit([&counter] {
                ++counter;
            });
        }
    }

    std::cout << "counter = " << counter.load() << std::endl;

    if (counter.load() != 100)
    {
        std::cout << "thread pool test failed" << std::endl;
        return 1;
    }

    std::cout << "thread pool test passed" << std::endl;
    return 0;
}

#include "ThreadPool.h"

#include <stdexcept>
#include <utility>

ThreadPool::ThreadPool(std::size_t thread_count)
    : stopping_(false)
{
    if (thread_count == 0)
    {
        throw std::invalid_argument("thread_count must be greater than 0");
    }

    workers_.reserve(thread_count);
    for (std::size_t i = 0; i < thread_count; ++i)
    {
        workers_.emplace_back(&ThreadPool::worker_loop, this);
    }
}

ThreadPool::~ThreadPool()
{
    {
        std::lock_guard<std::mutex> lock(mutex_);
        stopping_ = true;
    }

    condition_.notify_all();

    for (auto& worker : workers_)
    {
        if (worker.joinable())
        {
            worker.join();
        }
    }
}

void ThreadPool::submit(std::function<void()> task)
{
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (stopping_)
        {
            throw std::runtime_error("cannot submit task after pool is stopping");
        }
        tasks_.push(std::move(task));
    }

    condition_.notify_one();
}

void ThreadPool::worker_loop()
{
    while (true)
    {
        std::function<void()> task;

        {
            std::unique_lock<std::mutex> lock(mutex_);
            condition_.wait(lock, [this] {
                return stopping_ || !tasks_.empty();
            });

            if (stopping_ && tasks_.empty())
            {
                return;
            }

            task = std::move(tasks_.front());
            tasks_.pop();
        }

        task();
    }
}

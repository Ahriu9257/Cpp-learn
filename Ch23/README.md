# Ch23 - 多线程基础

本章目标是实现一个最小可用的线程池，练习 `std::thread`、`std::mutex`、`std::condition_variable` 和 `std::atomic` 的基本配合。

## 代码结构

- `ThreadPool.h`: 声明线程池接口，禁止拷贝，提供 `submit()` 提交无返回值任务。
- `ThreadPool.cpp`: 创建 worker 线程，使用任务队列和条件变量分发任务，析构时停止接收任务并 `join()` 所有线程。
- `thread_pool_test.cpp`: 提交 100 个递增任务，用 `std::atomic<int>` 验证最终计数。
- `CMakeLists.txt`: 构建 `thread_pool_test`，并链接 pthread。

## 核心知识点

- `std::thread` 启动后必须 `join()` 或 `detach()`，本章使用 `join()` 管理生命周期。
- `std::mutex` 保护共享任务队列，防止多个线程同时读写。
- `std::condition_variable` 让 worker 在线程池空闲时阻塞等待，而不是空转。
- `std::atomic<int>` 适合本章这种简单计数，不需要额外加锁。
- 析构函数负责通知所有 worker 退出，是 RAII 思想在并发资源管理里的应用。

## 构建与运行

```bash
cmake -S Ch23 -B /tmp/cpp-learn-build/ch23
cmake --build /tmp/cpp-learn-build/ch23
/tmp/cpp-learn-build/ch23/thread_pool_test
```

期望输出包含:

```text
counter = 100
thread pool test passed
```

## 复盘问题

- 为什么 `condition_.wait()` 要带一个谓词，而不是只调用 `wait(lock)`?
- 为什么析构函数先设置 `stopping_ = true`，再 `notify_all()`?
- 如果 `counter` 换成普通 `int`，会出现什么数据竞争风险?

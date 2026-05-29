# Ch24 - C++ 与 C 互操作

本章目标是实现一个 C 数学库和 C++ 包装层，理解 `extern "C"`、C ABI、C 风格接口和 CMake 链接关系。

## 代码结构

- `mathlib.h`: C/C++ 双语兼容头文件，使用 `extern "C"` 避免 C++ name mangling。
- `mathlib.c`: C 实现，提供 `mathlib_mean()` 和 `mathlib_stddev()`。
- `Statistics.h`: C++ 包装类接口，对外使用 `std::vector<double>`。
- `Statistics.cpp`: 将 `std::vector` 转成 `double* + size_t`，再调用 C 函数。
- `test.cpp`: 验证 C 函数和 C++ 包装层的计算结果。
- `CMakeLists.txt`: 将 C 文件编译成静态库 `mathlib`，再让 C++ 库和测试程序链接它。

## 核心知识点

- `extern "C"` 只解决符号名链接问题，不负责类型安全、内存所有权和库链接。
- 跨 C/C++ 边界时，接口应优先使用 C 能理解的类型，比如基础类型、指针、长度和普通结构体。
- 不要让 `std::vector`、`std::string`、模板、引用或 C++ 异常直接穿过 C ABI 边界。
- C++ 包装层负责提供更好用的对象接口，内部再转换成 C API 所需的简单参数。
- CMake 仍然需要明确声明目标之间的链接关系，`extern "C"` 不会自动链接库。

## 构建与运行

```bash
cmake -S Ch24 -B /tmp/cpp-learn-build/ch24
cmake --build /tmp/cpp-learn-build/ch24
/tmp/cpp-learn-build/ch24/ch24_test
ctest --test-dir /tmp/cpp-learn-build/ch24
```

期望输出包含:

```text
Ch24 C/C++ interop test passed
100% tests passed
```

## 复盘问题

- 如果删掉 `mathlib.h` 里的 `extern "C"`，C++ 链接 C 函数时可能出现什么错误?
- 为什么 `Statistics` 不把 `std::vector<double>` 直接传给 C 函数?
- 为什么 C API 更常见的错误处理方式是返回错误码，而不是抛 C++ 异常?

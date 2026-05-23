# C++ 学习记录

这个仓库用于记录从 C 语言基础过渡到 C++ 的系统学习过程。当前进度已经完成到 **Ch06 继承与多态**，每一章都围绕一个小任务展开，尽量保持代码短、主题明确、便于复盘。

## 当前进度

| 章节 | 主题 | 主要产出 |
|------|------|----------|
| Ch01 | 第一个 C++ 程序与编译流程 | `hello.cpp`：输入姓名和年龄，输出 10 年后的年龄 |
| Ch02 | 引用、`const`、函数重载、默认参数 | `overload.cpp`：实现 `print_value` 的多种重载 |
| Ch03 | 内联函数、作用域、初始化方式 | `counter.cpp`：用静态局部变量实现递增 ID |
| Ch04 | 类与对象入门 | `Sensor` 类拆分为头文件、实现文件和 `main.cpp` |
| Ch05 | 构造、析构、初始化列表 | 扩展 `Sensor`，观察栈对象和堆对象的析构时机 |
| Ch06 | 继承与多态 | 设计 `ISensor` 接口和两个传感器派生类 |

完整学习路线见 [plan.md](plan.md)。

## 目录结构

```text
.
├── Ch01/        # iostream、cin/cout、基本编译
├── Ch02/        # 函数重载、默认参数、const 引用
├── Ch03/        # inline、static 局部变量、auto
├── Ch04/        # 类、对象、头文件与实现文件拆分
├── Ch05/        # 构造函数、析构函数、初始化列表
├── Ch06/        # 继承、虚函数、抽象接口、多态
├── plan.md      # 后续章节学习计划
└── README.md
```

## 编译方式

前三章可以直接用 `g++` 编译：

```bash
g++ -std=c++14 -Wall -Wextra -g Ch01/hello.cpp -o /tmp/ch01_hello
g++ -std=c++14 -Wall -Wextra -g Ch02/overload.cpp -o /tmp/ch02_overload
g++ -std=c++14 -Wall -Wextra -g Ch03/counter.cpp -o /tmp/ch03_counter
```

Ch04 到 Ch06 可以用 CMake，也可以直接用 `g++`：

```bash
cmake -S Ch04 -B /tmp/cpp-learn-build/ch04 && cmake --build /tmp/cpp-learn-build/ch04
cmake -S Ch05 -B /tmp/cpp-learn-build/ch05 && cmake --build /tmp/cpp-learn-build/ch05
cmake -S Ch06 -B /tmp/cpp-learn-build/ch06 && cmake --build /tmp/cpp-learn-build/ch06
```

本仓库只提交源码和学习文档，IDE 配置、构建目录和本地可执行文件会被 `.gitignore` 忽略。

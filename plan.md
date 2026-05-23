# C++ 学习计划(系统学习,面向通用工程能力 + AI 边缘计算长期方向)

> **学习者画像**:有 C 语言基础,C++ 零基础。本 plan **专注 C++ 语言与工程能力本身**,不掺 Qt/嵌入式专项内容(那些走独立学习轨道)。
> **目标版本**:以 C++11/14 为主。
> **节奏**:快速入门、边用边学,每章一个独立小任务。
> **建议工具**:
> - 开发机:VS Code / CLion + g++ (Linux/WSL/macOS 都行)
> - 构建:先 `g++` 命令行 → 中期 `Makefile` → 后期 `CMake`
> - 调试:`gdb`(断点/单步)、`valgrind`(内存泄漏/越界)
> - 测试:`GoogleTest`(后期章节引入)

---

## 总览

| 阶段 | 章节 | 核心目标 |
|------|------|---------|
| 一、从 C 到 C++ | Ch01-Ch03 | 语法迁移、引用、函数增强 |
| 二、面向对象基础 | Ch04-Ch07 | 类、构造析构、继承多态、RAII |
| 三、现代 C++ 核心 | Ch08-Ch11 | 智能指针、移动语义、Lambda、auto |
| 四、STL 实战 | Ch12-Ch14 | 容器、迭代器、算法 |
| 五、模板与泛型 | Ch15-Ch16 | 函数模板、类模板入门 |
| 六、系统编程 | Ch17-Ch19 | 文件 IO、异常、命名空间 |
| 七、工程化工具链 | Ch20-Ch22 | GDB+Valgrind、单元测试、CMake |
| 八、并发与互操作 | Ch23-Ch24 | 多线程、`extern "C"` |
| 九、综合项目 | Ch25 | Mini Tensor 库(贴近 AI 长期方向) |

---

## Ch01 — 第一个 C++ 程序与编译流程

**学习要点**
- `iostream` vs `stdio.h`:`std::cout`、`std::cin`、`std::endl`
- 命名空间 `namespace`、`using` 的两种用法及风险
- `bool`、`true`/`false` 是真正的关键字
- C++ 的更严格类型检查(隐式转换比 C 少)
- 编译命令:`g++ -std=c++14 -Wall -Wextra -g main.cpp -o main`

**小任务 T01**
写一个 `hello.cpp`,要求:
1. 提示用户输入姓名和年龄(分别用 `std::cin`)
2. 计算并输出"你 10 年后是 X 岁"
3. 用 `g++ -std=c++14 -Wall` 编译,**保证无 warning**
4. 把编译命令写在文件顶部注释里

**产出**:`ch01/hello.cpp`

---

## Ch02 — 引用、const、函数重载、默认参数

**学习要点**
- 引用 `int&`:不是指针,但底层类似;必须初始化,不能改绑
- `const int&` 万能形参(避免拷贝又防修改)
- 函数重载:按参数类型/个数区分,**不按返回值**
- 默认参数:从右往左给,头文件里写一次
- `nullptr` 替代 `NULL`

**小任务 T02**
实现以下三个重载函数 `print_value`:
1. `void print_value(int x)` — 打印整数
2. `void print_value(double x)` — 打印浮点(保留 2 位小数)
3. `void print_value(const std::string& s, bool quoted = true)` — 默认带引号打印

main 中各调用一次,观察重载分发结果。

**产出**:`ch02/overload.cpp`

---

## Ch03 — 内联函数、作用域、初始化方式

**学习要点**
- `inline` 的真实含义(建议 + ODR 豁免)
- 块作用域、静态局部变量(C++ 中线程安全初始化)
- 三种初始化:`int x = 5;`、`int x(5);`、`int x{5};`(列表初始化禁止窄化)
- `auto` 的初步使用

**小任务 T03**
写一个 `Counter` 单例小工具(暂用函数模拟,不用类):
- 函数 `int next_id()`,每次调用返回递增 ID,从 1 开始
- 用 static 局部变量实现
- main 中循环调用 5 次,打印结果

**产出**:`ch03/counter.cpp`

---

## Ch04 — 类与对象入门

**学习要点**
- `class` vs `struct`(只差默认访问权限)
- 成员函数、`this` 指针
- 访问控制:`public`/`private`/`protected`
- 类内声明 + 类外定义的写法(`.h` / `.cpp` 拆分)
- 头文件保护:`#pragma once` 或 `#ifndef`

**小任务 T04**
实现一个 `Sensor` 类(模拟 AP3216C 数据载体):
- 私有成员:`float lux`(光照)、`uint16_t ir`(红外)、`uint16_t ps`(接近)
- 公有方法:`set(float, uint16_t, uint16_t)`、`print() const`
- **拆分成 `Sensor.h` 和 `Sensor.cpp`**,main 在 `main.cpp`
- 编译:`g++ -std=c++14 main.cpp Sensor.cpp -o app`

**产出**:`ch04/Sensor.h`、`ch04/Sensor.cpp`、`ch04/main.cpp`

---

## Ch05 — 构造、析构、初始化列表

**学习要点**
- 默认构造、参数化构造、拷贝构造
- **成员初始化列表**(为什么必须用、与构造体内赋值的区别)
- 析构函数 `~ClassName()`:何时被调用
- `explicit` 防止隐式转换
- 默认/删除函数:`= default`、`= delete`

**小任务 T05**
扩展 `Sensor` 类:
1. 加一个参数化构造,用初始化列表初始化所有成员
2. 加析构,打印 `"Sensor destroyed: <地址>"`
3. main 中创建栈对象、`new` 堆对象各一个,观察析构时机
4. 标记单参数构造为 `explicit`

**产出**:`ch05/Sensor.{h,cpp}`、`ch05/main.cpp`

---

## Ch06 — 继承与多态

**学习要点**
- 继承语法 `class Derived : public Base`
- `virtual` 函数、`override` 关键字、纯虚 `= 0`
- 虚析构函数(为什么基类析构必须 virtual)
- `final` 关键字
- 不要滥用继承,优先组合

**小任务 T06**
设计一个传感器抽象层:
- 基类 `ISensor`:纯虚 `read()`、纯虚 `name() const`、**虚析构**
- 派生类 `AP3216CSensor`(模拟读光照)、`MockTempSensor`(模拟读温度,返回随机数)
- main 中用 `std::vector<ISensor*>` 装两种传感器,循环调用 `read()`
- 程序结束前手动 `delete`(下章会改用智能指针)

**产出**:`ch06/sensors/*.{h,cpp}`

---

## Ch07 — RAII 思想

**学习要点**
- RAII:Resource Acquisition Is Initialization,**C++ 最重要的思想**
- 构造拿资源、析构还资源
- 与 C 的对比:C 需要手动 `free`/`close`,C++ 让析构自动做
- 典型场景:文件、互斥锁、动态内存、句柄

**小任务 T07**
写一个 `FileHandle` 类,封装 C 的 `FILE*`:
- 构造接收文件名+模式,内部 `fopen`,失败则抛异常(或打印错误)
- 析构 `fclose`
- 提供 `write(const std::string&)` 方法
- 禁用拷贝(`= delete`)防止双重 close
- main 中正常使用 + 故意触发异常路径,观察析构是否被调用

**产出**:`ch07/FileHandle.{h,cpp}`、`ch07/main.cpp`

---

## Ch08 — 智能指针:unique_ptr / shared_ptr

**学习要点**
- `std::unique_ptr<T>`:独占所有权,不可拷贝可移动
- `std::shared_ptr<T>`:共享所有权,引用计数
- `std::make_unique`(C++14)、`std::make_shared`
- 循环引用问题 + `std::weak_ptr`
- 嵌入式场景:堆资源管理首选

**小任务 T08**
用 Ch06 的传感器代码,**改造**:
1. `std::vector<std::unique_ptr<ISensor>>` 装传感器
2. 用 `std::make_unique` 创建
3. 删除所有手动 `delete`,验证程序退出时析构自动调用
4. 体会:不写 delete,内存却被正确释放

**产出**:`ch08/sensors/*.{h,cpp}`

---

## Ch09 — 移动语义、右值引用初步

**学习要点**
- 左值 vs 右值的直觉理解
- `&&` 右值引用(只在能区分时记忆)
- `std::move`:本质是 `static_cast<T&&>`,**不真正移动**
- 移动构造、移动赋值的写法
- 嵌入式实用:把大缓冲区 `vector<uint8_t>` 转移所有权,避免拷贝

**小任务 T09**
写一个 `Buffer` 类:
- 持有 `uint8_t* data` 和 `size_t size`
- 构造:`Buffer(size_t n)` 分配 `n` 字节
- **实现 5 大函数**:拷贝构造、拷贝赋值、移动构造、移动赋值、析构
- main 中用 `std::move` 把一个 Buffer 转移到另一个,打印两者的内部指针(被移动方应为 nullptr)

**产出**:`ch09/Buffer.{h,cpp}`、`ch09/main.cpp`

---

## Ch10 — Lambda 与 std::function

**学习要点**
- Lambda 语法:`[捕获](参数) -> 返回类型 { 体 }`
- 捕获方式:`[=]` 值、`[&]` 引用、`[this]`、混合捕获
- `std::function<返回(参数)>` 通用可调用对象
- 与函数指针的关系:Lambda **无捕获**时可隐式转函数指针
- 嵌入式实用:回调注册、事件处理

**小任务 T10**
写一个简单的事件分发器:
- 类 `EventBus`,内部 `std::vector<std::function<void(int)>>`
- 方法 `subscribe(std::function<void(int)>)`、`emit(int value)`
- main 中注册 2 个 Lambda(一个捕获引用计数器、一个打印),`emit(42)` 测试

**产出**:`ch10/EventBus.{h,cpp}`、`ch10/main.cpp`

---

## Ch11 — auto、范围 for、统一初始化、enum class

**学习要点**
- `auto` 推导规则与陷阱(`auto x = expr;` 不带引用/const)
- `for (auto& item : container)` 范围循环
- 列表初始化 `{}` 防止窄化
- `enum class`:强类型枚举,不污染命名空间
- 嵌入式实用:用 `enum class SensorType : uint8_t { Light, Temp, ... }` 替代 `#define`

**小任务 T11**
重写 Ch06 的传感器代码:
1. 用 `enum class SensorType { Light, Temp, Proximity }` 标识类型
2. `ISensor` 加 `virtual SensorType type() const = 0`
3. main 用范围 for + auto 遍历容器,根据 `type()` 打印不同前缀
4. 用 switch 处理 enum class(注意需要 `SensorType::Light` 写法)

**产出**:`ch11/sensors/*.{h,cpp}`

---

## Ch12 — STL 容器(一):vector / array / string

**学习要点**
- `std::vector<T>`:动态数组,核心容器
- `std::array<T, N>`:栈上固定数组(嵌入式友好)
- `std::string`:不要再用 char[] 了
- 常用接口:`push_back`/`emplace_back`、`size`/`capacity`、`reserve`、`clear`
- 迭代器入门:`begin()`/`end()`、`auto it = v.begin();`

**小任务 T12**
写一个传感器历史记录器:
- `std::vector<float>` 存储最近 N 次光照值
- 方法 `push(float)`(超出容量则丢弃最旧的)
- 方法 `average() const` 返回平均值
- main 中模拟 push 10 个值(容量设为 5),打印当前数据和平均

**产出**:`ch12/History.{h,cpp}`

---

## Ch13 — STL 容器(二):map / unordered_map / set

**学习要点**
- `std::map`(红黑树,有序)vs `std::unordered_map`(哈希,平均 O(1))
- `[]` 与 `at()`、`find()`、`insert()` 区别
- `std::pair`、结构化绑定(C++17 顺便了解)
- `std::set` 去重需求
- 嵌入式注意:hash 表内存占用大,小数据用 map 即可

**小任务 T13**
写一个传感器注册中心:
- `std::unordered_map<std::string, std::unique_ptr<ISensor>>`,键为传感器名
- 方法 `register_sensor(name, unique_ptr)`、`read_by_name(name)`
- 注册名重复时打印警告并拒绝
- main 中注册 3 个不同传感器,用 name 读取数据

**产出**:`ch13/Registry.{h,cpp}`

---

## Ch14 — STL 算法 + Lambda 配合

**学习要点**
- 常用算法:`std::sort`、`std::find_if`、`std::for_each`、`std::transform`、`std::accumulate`
- 谓词(predicate)= Lambda
- 头文件:`<algorithm>` / `<numeric>`
- 学会"以算法替代手写循环"的思维

**小任务 T14**
对 Ch12 的历史数据:
1. 用 `std::accumulate` 重写 `average()`
2. 加方法 `count_above(float threshold) const`,用 `std::count_if`
3. 加方法 `sorted_copy() const`,返回排序后的副本(`std::sort`)
4. 全程不写裸 `for (int i = 0; ...)` 循环

**产出**:`ch14/History.{h,cpp}`

---

## Ch15 — 函数模板

**学习要点**
- `template <typename T>` 语法
- 模板参数推导
- 模板特化(简单了解)
- 编译期 vs 运行期分发的对比
- 嵌入式注意:模板会生成多份代码,留意 flash 占用

**小任务 T15**
写一个泛型 `clamp` 函数:
- `template <typename T> T clamp(T value, T lo, T hi)`
- 测试 int、float、double 三种类型
- 思考:如果传 `clamp(1, 2.0, 3)` 会编译失败吗?为什么?(类型推导冲突)

**产出**:`ch15/clamp.cpp`

---

## Ch16 — 类模板入门

**学习要点**
- `template <typename T> class Foo { ... };`
- 类模板的方法必须写在头文件里(or `.tpp`)
- 模板与继承的简单结合
- STL 容器本质就是类模板

**小任务 T16**
写一个固定容量的环形缓冲区 `RingBuffer<T, N>`:
- 模板参数:类型 T、容量 N(非类型模板参数)
- 接口:`push(T)`、`pop()`、`size()`、`empty()`、`full()`
- 满时 push 覆盖最旧;空时 pop 抛异常
- main 中分别用 `RingBuffer<int, 4>` 和 `RingBuffer<std::string, 3>` 测试

**产出**:`ch16/RingBuffer.h`、`ch16/main.cpp`

---

## Ch17 — 文件 IO 与字符串处理

**学习要点**
- `<fstream>`:`std::ifstream`、`std::ofstream`、`std::fstream`
- `std::getline`、`std::stringstream`
- 字符串切分、转数字 `std::stoi`/`std::stof`
- 文本配置文件解析(几乎所有应用都需要)

**小任务 T17**
写一个简易配置文件读取器:
- 文件格式:`key = value`,每行一对,`#` 开头为注释
- 类 `ConfigReader`,接口:`load(filename)`、`get(key)` 返回 string、`get_int(key)`
- 处理:空行、注释行、value 前后空格
- main 读取一个示例 `app.conf`,打印所有键值

**产出**:`ch17/ConfigReader.{h,cpp}`、`ch17/app.conf`、`ch17/main.cpp`

---

## Ch18 — 异常处理

**学习要点**
- `try` / `catch` / `throw`
- 标准异常 `std::exception`、`std::runtime_error`、`std::out_of_range`
- 异常安全(基本/强/无抛出保证)
- 何时不该用异常:性能敏感/受限环境(`-fno-exceptions`)、跨 ABI 边界,这时用错误码/`std::optional`/`std::expected`(C++23)替代

**小任务 T18**
扩展 Ch17 的 `ConfigReader`:
1. 自定义异常 `ConfigError`,继承 `std::runtime_error`
2. 文件打不开 / `get_int` 解析失败时抛 `ConfigError`
3. main 中用 try/catch 处理,打印友好错误

**产出**:`ch18/ConfigReader.{h,cpp}`、`ch18/main.cpp`

---

## Ch19 — 命名空间、头文件最佳实践

**学习要点**
- 自定义命名空间组织代码
- 嵌套命名空间(C++17 简写 `namespace a::b`)
- 头文件该放什么、不该放什么(实现细节、`using namespace` 等不放头文件)
- 前向声明减少编译依赖
- include 顺序约定(自己的→第三方→系统)

**小任务 T19**
把前面所有传感器代码整理为一个小库:
- 全部塞进 `namespace mylib::sensor`
- 目录结构:`include/mylib/sensor/*.h`,`src/*.cpp`
- 写一个 `main.cpp` 使用这个库,编译命令:`g++ -Iinclude src/*.cpp main.cpp -o app`

**产出**:`ch19/include/`、`ch19/src/`、`ch19/main.cpp`

---

## Ch20 — 调试工具:GDB + Valgrind

**学习要点**
- 编译加 `-g`(保留调试符号),`-O0`(关优化避免行号错乱)
- GDB 核心命令:
  - 启动 `gdb ./app`、`run`、`run arg1 arg2`
  - 断点 `break main`、`break Sensor.cpp:42`、`info break`、`delete N`
  - 单步 `next`(过)、`step`(进)、`continue`、`finish`(跳出当前函数)
  - 查看 `print var`、`p *ptr`、`p obj.member`、`backtrace`
  - 监视 `watch var`(变量被修改时停下)
- 调试 segfault:程序崩溃后 `bt` 看调用栈
- Valgrind 核心用法:
  - `valgrind --leak-check=full ./app` 找内存泄漏
  - 看输出里的 "definitely lost / indirectly lost / still reachable" 含义
  - `valgrind --tool=helgrind ./app` 检多线程数据竞争
- VS Code 也行,但**至少要会命令行 gdb**

**小任务 T20**
准备一段"问题代码"`buggy.cpp`,故意写以下三种 bug:
1. 一个**段错误**:解引用未初始化的指针
2. 一个**内存泄漏**:`new` 了一个对象但忘记 `delete`
3. 一个**逻辑 bug**:循环边界写错(off-by-one)

然后:
- 用 gdb 定位段错误位置(`bt`),截图或贴出会话记录
- 用 valgrind 报告内存泄漏,确认行号
- 用 gdb 断点+watch 定位逻辑 bug
- 修复全部 3 个 bug,验证 valgrind 输出 "no leaks are possible"

**产出**:`ch20/buggy.cpp`(修复前)、`ch20/fixed.cpp`(修复后)、`ch20/debug_notes.md`(gdb/valgrind 操作记录)

---

## Ch21 — 单元测试:GoogleTest 入门

**学习要点**
- 为什么写测试:回归保障 + 设计倒逼 + 文档作用
- 安装:`apt install libgtest-dev` 或 CMake `FetchContent`(下一章会用)
- 核心断言:`EXPECT_EQ`、`EXPECT_NE`、`EXPECT_TRUE`、`EXPECT_THROW`、`EXPECT_NEAR`(浮点)
- `EXPECT_*` vs `ASSERT_*`:前者继续、后者中断当前测试
- `TEST(SuiteName, TestName) { ... }` 与 `TEST_F`(fixture)区别
- 编译链接:`g++ test.cpp -lgtest -lgtest_main -pthread`
- 跑测试:`./test --gtest_filter=Foo.*`、`--gtest_repeat=10`

**小任务 T21**
回头给 Ch16 的 `RingBuffer<T, N>` 写完整单元测试:
1. 测试 push/pop 基本顺序(FIFO)
2. 测试空 buffer pop 抛异常 → `EXPECT_THROW`
3. 测试满 buffer 继续 push 会覆盖最旧元素
4. 用 `TEST_F` fixture 准备一个共享的 `RingBuffer<int, 3>`
5. 用 `EXPECT_NEAR` 测试浮点版本的容差(若你用 float 模板)
6. 故意改一行 RingBuffer 代码引入 bug,确认测试能抓住它

**产出**:`ch21/RingBuffer.h`(拷过来或符号链接)、`ch21/ring_buffer_test.cpp`、`ch21/run_test.sh`

---

## Ch22 — CMake 入门

**学习要点**
- 为什么从 Makefile 升级到 CMake:跨平台、依赖管理、IDE 支持
- 最小 `CMakeLists.txt`:`cmake_minimum_required`、`project`、`add_executable`、`target_link_libraries`、`target_include_directories`
- 设置标准:`set(CMAKE_CXX_STANDARD 14)`、`CMAKE_CXX_STANDARD_REQUIRED ON`、`CMAKE_CXX_EXTENSIONS OFF`
- 编译选项:`target_compile_options(target PRIVATE -Wall -Wextra)`
- 多 target:库 + 可执行文件 + 测试三个 target
- `FetchContent` 拉 GoogleTest(无需系统安装)
- `enable_testing()` + `add_test()` + `ctest` 集成测试

**小任务 T22**
把 Ch19 的小库 + Ch21 的测试整合成一个 CMake 工程:
1. 顶层 `CMakeLists.txt`,定义 `mylib` 静态库(库源码)
2. `app` 可执行文件链接 `mylib`
3. `tests/CMakeLists.txt`,用 `FetchContent` 拉 gtest,链接 `mylib`
4. `enable_testing()` + `add_test(NAME ring_buffer_test COMMAND ring_buffer_test)`
5. 构建命令:`cmake -B build && cmake --build build -j && ctest --test-dir build`

**产出**:`ch22/CMakeLists.txt`、`ch22/src/`、`ch22/include/`、`ch22/tests/CMakeLists.txt`、`ch22/tests/*.cpp`

---

## Ch23 — 多线程基础

**学习要点**
- `std::thread`、`join`/`detach`(detach 后线程独立运行,析构不会等)
- `std::mutex`、`std::lock_guard`(RAII 锁)、`std::unique_lock`(更灵活)
- `std::condition_variable`:`wait` / `notify_one` / `notify_all`
- `std::atomic<T>`:无锁的简单同步
- 何时用 `std::async` / `std::future` 拿返回值
- 编译加 `-pthread`
- 用 valgrind helgrind 检查数据竞争

**小任务 T23**
写一个**线程池**(后续综合项目会用到):
- `class ThreadPool { ... }`,构造接收线程数 N
- 方法 `submit(std::function<void()> task)`:把任务加入队列
- 内部 N 个 worker 线程消费队列,用 `condition_variable` 等待新任务
- 析构时:停止接收新任务,等所有 worker 退出(join)
- 写单元测试(用上一章的 gtest):提交 100 个 +1 任务到原子计数器,验证最终结果 == 100

**产出**:`ch23/ThreadPool.{h,cpp}`、`ch23/thread_pool_test.cpp`、`ch23/CMakeLists.txt`

---

## Ch24 — C++ 与 C 互操作

**学习要点**
- `extern "C"`:消除 C++ name mangling,让 C++ 能链接 C 函数
- 头文件双语兼容写法:`#ifdef __cplusplus extern "C" { #endif ... #ifdef __cplusplus } #endif`
- POD(Plain Old Data)类型:跨 C/C++ 边界传递的安全结构体
- ABI 注意事项:C++ 异常、引用、模板都不能跨 `extern "C"` 边界
- 静态库 `.a` 与动态库 `.so` 的链接(`-L` / `-l`)
- 反向:C 调用 C++ 代码(需要 C++ 端导出 `extern "C"` 包装函数)

**小任务 T24**
写一个 "C 数学库 + C++ 包装" 的小项目:
1. C 文件 `mathlib.c`:提供 `double mathlib_mean(const double* arr, size_t n);` 和 `double mathlib_stddev(const double* arr, size_t n);`
2. C 头文件 `mathlib.h`,用 `extern "C"` 双语保护
3. C++ 包装类 `Statistics`,接收 `std::vector<double>`,内部转 C 数组调上面函数
4. 用 gtest 测试 C++ 包装类的正确性
5. 用 CMake 构建:C 编译成静态库 `libmathlib.a`,C++ 链接它

**产出**:`ch24/mathlib.{c,h}`、`ch24/Statistics.{h,cpp}`、`ch24/test.cpp`、`ch24/CMakeLists.txt`

---

## Ch25 — 综合项目:Mini Tensor 库

> 一个**纯 C++ 项目**,不依赖嵌入式硬件,跑在你的开发机上即可。
> 选这个主题的原因:贴近你的 AI 边缘计算长期方向,后续读 NCNN/TFLite 源码会顺很多;同时它能把前面几乎所有章节的能力都串起来。
> 如果你**不喜欢这个方向**,文末列了两个备选方案,可以替换。

### 目标
实现一个支持 1D/2D 的 `Tensor<T>` 库,提供基础运算和小型神经网络前向推理能力。**不做训练**,只做 inference。

### 功能需求
1. **`Tensor<T>` 类模板**(`T` = `float` / `double`)
   - 支持形状:`Tensor<float> t({2, 3})` 表示 2×3 矩阵
   - 内部用 `std::vector<T>` 存数据,行优先(row-major)
   - 实现 5 大函数(拷贝/移动/析构,Ch09 知识点)
   - `operator()(i, j)` 索引访问、`shape()`、`size()`
   - 工厂函数:`Tensor::zeros(shape)`、`Tensor::ones(shape)`、`Tensor::randn(shape)`
2. **基础算子**(返回新 Tensor,不修改输入)
   - `add`、`sub`、`mul`(逐元素)、`matmul`(矩阵乘)
   - `relu`、`sigmoid`、`softmax`
   - `transpose`、`reshape`
3. **简易神经网络层**
   - `class Linear { Tensor weight, bias; Tensor forward(const Tensor&); };`(全连接层)
   - `class ReLU { Tensor forward(const Tensor&); };`
   - 提供顺序组合工具(简单的 `Sequential` 类即可)
4. **权重加载**
   - 从文本文件加载(Ch17 文件 IO)
   - 格式自定义:每行 "shape行 + 数据行"
5. **错误处理**(Ch18)
   - 形状不匹配 → 抛 `TensorShapeError`(自定义异常,继承 `std::runtime_error`)
6. **并行加速**(Ch23)
   - `matmul` 的内层循环用 Ch23 的 ThreadPool 切分,N 个线程并行
   - 提供开关:小矩阵直接串行,大矩阵才走线程池
7. **CLI demo**
   - 写一个 `mnist_infer` 可执行文件,加载预制权重,对一张 28×28 的灰度图(用文本 PGM 格式)做前向推理,输出预测数字
   - 权重和样本图可以预先准备好放在 `data/` 目录(或先做个不需要 MNIST 的简化版:2 层网络 + 4 个手造样本)

### 工程要求
- 全程**零裸 `new`/`delete`**
- `Tensor` **移动语义正确**(返回值不要触发拷贝)
- 用 namespace `mytensor` 组织
- CMake 构建:库 + demo + 测试三个 target
- **每个算子都有 gtest 单元测试**(Ch21 知识点)
- 跑 `valgrind ./mnist_infer` 无泄漏

### 验收标准
- `ctest` 全绿
- valgrind 干净
- 至少手造一个 2 层网络(线性 → ReLU → 线性 → softmax),对 4 个样本做推理,结果可解释
- 写一份 `ch25/REPORT.md`,总结:用到了哪些章节的知识、遇到了什么坑、性能数据(单线程 vs 4 线程 matmul)

**产出**:`ch25/` 完整工程(`include/`、`src/`、`tests/`、`demo/`、`data/`、`CMakeLists.txt`、`REPORT.md`)

### 备选综合项目(如果不想做 Tensor)
- **方案 B — 并发 KV 存储 / LRU Cache 服务**:多线程安全的 LRU + 简单命令行交互(SET/GET/DEL),覆盖 STL、模板、并发、单元测试
- **方案 C — 手写 JSON 解析器**:递归下降解析,得到 `json::Value` 变体,支持 parse/serialize,覆盖类设计、异常、字符串处理、单元测试

如果想切到 B 或 C,告诉我,我把 Ch25 节细化成对应内容。

---

## 学习节奏建议

- **每章 1-3 天**:概念 0.5 天 + 任务 1 天 + 复盘 0.5 天
- **每完成一个任务**,自问三件事:
  1. 这段代码用 C 写会怎样?C++ 让我少写/多写了什么?
  2. 有没有用裸 `new`/`delete`?能否换成智能指针?
  3. 异常安全吗?如果中间抛了异常,资源会泄漏吗?
- **从 Ch21 开始所有代码都写测试**,养成测试驱动的肌肉记忆
- **建议配套书**:《C++ Primer 中文版》(第 5 版)只查不通读;《Effective Modern C++》后期回头看
- **每完成一个阶段**(每 3-4 章)写一份小总结(可以丢给我帮你 review)

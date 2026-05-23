//
// Created by ahriu on 2026/5/23.
//
#include <iostream>

inline int square(int x)
{
    return x * x;
}

int next_id()
{
    // static 局部变量只初始化一次，后续调用会保留上一次的值。
    static int a{0};
    ++a;
    return a;
}

int main()
{
    auto counter{5};

    for (int i{0}; i < counter; ++i)
    {
        std::cout << next_id() << std::endl;
    }
    std::cout << "square(5) = " << square(5) << std::endl;

    return 0;
}

//
// Created by ahriu on 2026/5/23.
//
#include <iomanip>
#include <iostream>
#include <string>

void print_value(int x)
{
    std::cout << "int value = " << x << std::endl;
}

void print_value(double x)
{
    std::cout << "double value = " << std::fixed << std::setprecision(2) << x << std::endl;
}

// const 引用避免拷贝；quoted 控制是否带引号输出。
void print_value(const std::string& x, bool quoted = true)
{
    if (quoted)
    {
        std::cout << "string value = \"" << x << "\"" << std::endl;
    }
    else
    {
        std::cout << "string value = " << x << std::endl;
    }
}

int main()
{
    int a = 32;
    double b = 3.14;
    std::string c = "hello c++";

    print_value(a);
    print_value(b);
    print_value(c);
    print_value(c, false);

    print_value("ok malec");

    return 0;
}

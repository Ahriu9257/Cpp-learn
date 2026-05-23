// 编译: g++ -std=c++14 -Wall -Wextra -g hello.cpp -o hello
#include <iostream>
#include <string>

int main()
{
    std::string name;
    int age = 0;

    std::cout << "请输入你的名字" << std::endl;
    std::cin >> name;

    std::cout << "请输入你的年龄" << std::endl;
    std::cin >> age;

    int age_in_10_years = age + 10;

    std::cout << "你好," << name << "!" << std::endl;
    std::cout << "你十年后是" << age_in_10_years << "岁了!" << std::endl;

    return 0;
}

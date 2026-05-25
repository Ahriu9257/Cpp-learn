//
// Created by ahriu on 2026/5/24.
//
#include <iostream>
#include <ostream>

#include "Buffer.h"

int main()
{
    std::cout << "== create b1 ==" << std::endl;
    Buffer b1(16);
    b1.print("b1");

    std::cout << "== copy construct b2 from b1 ==" << std::endl;
    Buffer b2 = b1;
    b1.print("b1");
    b2.print("b2");

    std::cout << "== move construct b3 from b1 ==" << std::endl;
    Buffer b3 = std::move(b1);
    b1.print("b1");
    b3.print("b3");

    std::cout << "== copy assign b2 = b3" << std::endl;
    b2 = b3;
    b2.print("b2");
    b3.print("b3");

    std::cout << "== move assign b2 = std::move(b3)" << std::endl;
    b2 = std::move(b3);
    b2.print("b2");
    b3.print("b3");

    std::cout << "program end" << std::endl;

    return 0;
}
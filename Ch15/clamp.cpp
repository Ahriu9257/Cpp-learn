#include <iostream>

template <typename T>
T clamp(T value, T low, T high)
{
    if (value <low) return low;
    if (value > high) return high;
    return value;
}

int main()
{
    int a = clamp(10, 0, 5);
    double b = clamp(-3.14, 0.0, 2.0);
    float c = clamp(1.5f, 0.0f, 1.0f);

    std::cout << "int result = " << a << std::endl;
    std::cout << "double result = " << b << std::endl;
    std::cout << "float result = " << c << std::endl;

    return 0;
}
#include "RingBuffer.h"
#include <iostream>

int main()
{
    std::cout << "RingBuffer test begin" << std::endl;

    RingBuffer<int, 5> buffer_int;
    buffer_int.push(1);
    buffer_int.push(2);
    buffer_int.push(3);
    buffer_int.push(4);
    buffer_int.push(5);
    std::cout << "Buffer size: " << buffer_int.size() << std::endl;
    std::cout << "Buffer full: " << std::boolalpha << buffer_int.full() << std::endl;

    buffer_int.push(6); // This will overwrite the oldest element (1)
    std::cout << "Buffer size after pushing 6: " << buffer_int.size() << std::endl;
    std::cout << "Popped value: " << buffer_int.pop() << std::endl; // Should print 2
    std::cout << "Buffer size after popping: " << buffer_int.size() << std::endl;

    RingBuffer<std::string, 3> buffer_string;
    buffer_string.push("A");
    buffer_string.push("B");
    buffer_string.push("C");
    std::cout << "Buffer size: " << buffer_string.size() << std::endl;
    std::cout << "Popped value: " << buffer_string.pop() << std::endl; // Should print "A"
    std::cout << "Buffer size after popping: " << buffer_string.size() << std::endl;

    std::cout << "RingBuffer test end" << std::endl;
    return 0;
}
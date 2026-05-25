//
// Created by ahriu on 2026/5/24.
//

#ifndef CH06SENSORS_BUFFER_H
#define CH06SENSORS_BUFFER_H

#pragma once
#include <cstdint>

class Buffer
{
public:
    explicit Buffer(const std::size_t n);   //申请n字节空间
    ~Buffer();
    Buffer(const Buffer& other);
    Buffer& operator=(const Buffer& other);
    Buffer(Buffer&& other) noexcept;
    Buffer& operator=(Buffer&& other) noexcept;

    const uint8_t* data() const;
    std::size_t size() const;
    void print(const char* name) const;
private:
    uint8_t* data_;
    std::size_t size_;
};

#endif //CH06SENSORS_BUFFER_H

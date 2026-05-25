//
// Created by ahriu on 2026/5/24.
//
#include "Buffer.h"

#include <cstring>
#include <iostream>
#include <ostream>

Buffer::Buffer(std::size_t n)
    :data_(nullptr),size_(n)
{
    if (n == 0)
    {
        return;
    }
    data_ = new uint8_t[n];
    std::memset(data_, 0, n);
    std::cout << "[ctor] allocate" << size_
                << "bytes,data =" << static_cast<const void*>(data_) << std::endl;
}

Buffer::~Buffer()
{
    std::cout << "[dtor] release data = " << static_cast<const void*>(data_)
    << ", size = " << size_ << std::endl;

    delete[] data_;
}

Buffer::Buffer(const Buffer& other)
    :data_(nullptr),size_(other.size_)
{
    if (other.data_ != nullptr && other.size_ > 0)
    {
        data_ = new uint8_t[other.size_];
        std::memset(data_, 0, other.size_);
    }
    std::cout << "[copy ctor] from"
    << static_cast<const void*>(other.data_)
    << "to"
    << static_cast<const void*>(data_)
    << std::endl;
}

Buffer& Buffer::operator=(const Buffer& other)
{
    std::cout << "[copy assign] from"
    << static_cast<const void*>(other.data_)
    << "to"
    << static_cast<const void*>(data_)
    << std::endl;

    if (this == &other)
    {
        return *this;
    }

    uint8_t* new_data = nullptr;
    if (other.data_ != nullptr && other.size_ > 0)
    {
        new_data = new uint8_t[other.size_];
        std::memset(new_data, 0, other.size_);
    }
    delete[] data_;

    data_ = new_data;
    size_ = other.size_;
    return *this;
}

Buffer::Buffer(Buffer&& other) noexcept
    :data_(other.data_),size_(other.size_)
{
    other.data_ = nullptr;
    other.size_ = 0;

    std::cout << "[move ctor] steal data = "
    <<static_cast<const void*>(data_)
    <<std::endl;
}

Buffer& Buffer::operator=(Buffer&& other) noexcept
{
    std::cout << "[move assign] from"
    << static_cast<const void*>(other.data_)
    << "to"
    << static_cast<const void*>(data_)
    << std::endl;

    if (this == &other)
    {
        return *this;
    }

    delete[] data_;
    data_ = other.data_;
    size_ = other.size_;

    other.data_ = nullptr;
    other.size_ = 0;

    return *this;
}

const uint8_t* Buffer::data() const
{
    return data_;
}

std::size_t Buffer::size() const
{
    return size_;
}

void Buffer::print(const char* name) const
{
    std::cout << name
    << ": data = " << static_cast<const void*>(data_)
    << ", size = " << size_
    << std::endl;
}
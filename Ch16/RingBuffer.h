#pragma once

#include <array>
#include <cstddef>
#include <stdexcept>
#include <utility>

template <typename T, std::size_t N>

class RingBuffer
{
    static_assert(N > 0, "RingBuffer capacity must be greater than 0");

public:
    RingBuffer() = default;
    
    void push(T value)
    {
        data_[tail_] = std::move(value);
        tail_ = next_index(tail_);

        if(count_ < N) {++count_;}
        else {head_ = next_index(head_);}
    }

    T pop()
    {
        if(empty())
        {
            throw std::runtime_error("RingBuffer is empty");
        }
        T value = std::move(data_[head_]);
        head_ = next_index(head_);
        --count_;
        return value;
    }

    std::size_t size() const
    {
        return count_;
    }

    bool empty() const
    {
        return count_ == 0;
    }

    bool full() const
    {
        return count_ == N;
    }

    constexpr std::size_t capacity() const
    {
        return N;
    }

private:
    std::size_t next_index(std::size_t index) const
    {
        return (index + 1) % N;
    }

private:
    std::array<T, N> data_;
    std::size_t head_ = 0;
    std::size_t tail_ = 0;
    std::size_t count_ = 0;
};

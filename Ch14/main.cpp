//
// Created by ahriu on 2026/5/27.
//
#include <algorithm>
#include <iostream>
#include <iterator>
#include <ostream>

#include "History.h"

static void print_data(const std::vector<float>& datas)
{
    std::copy(datas.begin(), datas.end(), std::ostream_iterator<float>(std::cout, " "));
    std::cout << std::endl;
}

int main()
{
    History history(5);

    history.push(10.0);
    history.push(30.0);
    history.push(40.0);
    history.push(50.0);
    history.push(1.0);
    history.push(5.0);
    history.push(7.0);
    history.push(9.0);

    std::cout << "current data : ";
    print_data(history.get_data());

    std::cout << "average data : " << history.average() << std::endl;

    std::cout << "count above 5 : " << history.count_above(5) << std::endl;

    std::vector<float> copy = history.sort_copy();

    std::cout << "sorted copy : ";
    print_data(copy);

    std::cout << "original data : ";
    print_data(history.get_data());

    return 0;
}

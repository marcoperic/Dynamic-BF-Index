#pragma once
#include <string>

template<typename T>
int h1(T const& element)
{
    std::cout << element << std::endl;
    return 1;
}

template<typename T>
int h2(T const& element)
{
    std::cout << element << std::endl;
    return 2;
}

template<typename T>
int h3(T const& element)
{
    std::cout << element << std::endl;
    return 3;
}
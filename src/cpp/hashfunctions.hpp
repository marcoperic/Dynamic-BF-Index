#pragma once
#include <iostream>
#include <string>
#include "stdlib.h"
#include "md5.cpp"
#include "BigInt.hpp"
using namespace std;

template<typename T>
long long h1(T const& element, size_t filter_size) // md5
{
    auto hash = ConstexprHashes::md5(element);
    string temp = "";
    for (auto a: hash)
    {
        auto x = (static_cast<int>(a) & 0xff);
        temp.append(to_string(x));
    }

    BigInt n(temp);
    n %= filter_size;

    return n.to_long_long();
}

template<typename T>
int h2(T const& element, size_t filter_size) // sha1
{
    return 2;
}

template<typename T>
int h3(T const& element, size_t filter_size) // sha224
{
    return 3;
}
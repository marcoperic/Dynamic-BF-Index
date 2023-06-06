#pragma once
#include <iostream>
#include <string>
#include "stdlib.h"
#include "md5.cpp"
using namespace std;

template<typename T>
long long h1(T const& element) // md5
{
    auto hash = ConstexprHashes::md5(element);
    string temp = "";
    for (auto a: hash)
    {
        auto x = (static_cast<int>(a) & 0xff);
        temp.append(to_string(x));
    }

    cout << temp << endl;
    return 0;
}

template<typename T>
int h2(T const& element) // sha1
{
    return 2;
}

template<typename T>
int h3(T const& element) // sha224
{
    return 3;
}
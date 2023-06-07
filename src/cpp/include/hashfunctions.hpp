#pragma once
#include <iostream>
#include <string>
#include "stdlib.h"
#include "md5.cpp"
#include "sha1.hpp"
#include "BigInt.hpp"
#include "hex_conv.hpp"
#include "sha256.hpp"
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
long long h2(T const& element, size_t filter_size) // sha1
{
    SHA1 checksum;
    checksum.update(element);
    string hash = checksum.final();
    BigInt n(hexToDecimalString(hash));
    n %= filter_size;
    
    return n.to_long_long();
}

template<typename T>
long long h3(T const& element, size_t filter_size) // sha256
{
    string hash = SHA256((char*)element);
    BigInt n(hexToDecimalString(hash));
    n %= filter_size;

    return n.to_long_long();
}
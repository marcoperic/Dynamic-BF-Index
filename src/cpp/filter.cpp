#include <iostream>
#include "include/hashfunctions.hpp"
using namespace std;

class Filter
{
    private:
    int size = 10000;

    public:
    Filter()
    {
    }

    template <typename T>
    bool insert(T const& element)
    {
        long long hash_value[3] = {h1(element, size), h2(element, size), h3(element, size)};
        return true;
    }

    template <typename T>
    bool query(T const& element)
    {
        return true;
    }
};

int main()
{
    Filter f = Filter();
    f.insert("goomba");
    return 0;
}
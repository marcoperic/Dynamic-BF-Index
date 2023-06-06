#include <iostream>
#include "hashfunctions.hpp"
using namespace std;

class Filter
{
    private:
    int size = 0;

    public:
    Filter()
    {
    }

    template <typename T>
    bool insert(T const& element)
    {
        cout << h1(element) << endl;
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
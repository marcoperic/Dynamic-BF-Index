#include <iostream>
#include "include/hashfunctions.hpp"
using namespace std;

class Filter
{
    private:
    const size_t length = 10000; // BF not dynamic yet.
    const int hash_functions = 3;
    bool *data = new bool(length);
    size_t size = 110;
    float prob = 0.0;

    public:
    Filter()
    {
    }

    template <typename T>
    bool insert(T const& element)
    {
        long long hash_value[] = {h1(element, length), h2(element, length), h3(element, length)};        
        
        for (long long a: hash_value)
        {
            data[a] = true;
        }

        size++;
        cout << "insertion complete - new false positive rate is " << calculateFPRate() << endl;

        return true;
    }

    template <typename T>
    bool query(T const& element)
    {
        return true;
    }

    double calculateFPRate()
    {
        int k = hash_functions;
        return pow(1 - exp((-k * (size / (double)length))), k);
    }
};

int main()
{
    Filter f = Filter();
    f.insert("goomba");
    return 0;
}
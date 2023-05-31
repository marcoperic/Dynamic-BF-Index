#include <iostream>
using namespace std;

class Filter
{
    template<typename T>
    struct HashFunction{typedef void (*type) (T const& element);};
    template<typename T>
    void h1(T const& element);
    template<typename T>
    void h2(T const& element);
    template<typename T>
    void h3(T const& element);

    public:
    Filter()
    {
    }

    private:
    int size = 0;

    void h1()
    {

    }

    void h2()
    {

    }

    void h3()
    {

    }
};

int main()
{
    Filter f = Filter();
    return 0;
}